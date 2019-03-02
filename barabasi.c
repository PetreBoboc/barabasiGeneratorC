#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "barabasi.h"

void barabasi(int n, int m)
{

    double totalDeg = 0; // initial total degree is 0
    double probability; // probability
    double r = 0; // random number between 0 and 1

    srand(time(NULL)); // reset seed

    int *matrix[n]; // adjacency matrix (n x n size)
    for (int i = 0; i < n; i++)
        matrix[i] = (int*)malloc(n*sizeof(int));

    srand(time(NULL));

    double* deg = malloc(n*sizeof(double)); // node degree (n size)

    for(int i=0; i<n; i++)
    {
        deg[i]=0; // degree of each node is 0 (initially)
        for(int j=0; j<n; j++)
        {
            matrix[i][j]=0; // initialize adjaceny matrix (n size)
        }
    }

    for (int i=0; i<m; i++)
    for (int j=i+1; j<m; j++)
    {
        matrix[i][j]=matrix[j][i]=1; // create complety graph (size m)
        deg[i]++; // increment node i degree by 1
        deg[j]++; // increment node i degree by 1
    }

    for(int i=0; i<n; i++)
    {
        totalDeg = totalDeg + deg[i]; // calculate total degree
    }

    int connectedNodes = m; // m connected nodes (with degree > 0 )
    int currentNode = m; // current node is set to m
    int nodeJ = 0;

    FILE *output;
    output = fopen("network.net","w");

    FILE *x;
    x = fopen("x.txt","w");

    FILE *y;
    y = fopen("y.txt", "w");

    do
    {
        do
        {
            nodeJ = rand()%(connectedNodes); // generates a node between 0 and connectedNodes - 1
            probability = deg[nodeJ]/totalDeg; // calculates probability of connection
            double r = ((double) rand()/(RAND_MAX)); 

            if ( r < probability )
            {
                matrix[nodeJ][currentNode] = matrix[currentNode][nodeJ] = 1;
            }

            totalDeg=0;

            for(int i=0; i<=connectedNodes; i++)
            {
                deg[i]=0;  // resets every iteration the degree of every node to 0
            }

            for(int i=0; i<=connectedNodes; i++)
            for(int j=i+1; j<=connectedNodes; j++)
            {
                if(matrix[i][j]!=0)
                {
                    deg[i]++;
                    deg[j]++;
                }
            } // a better way to calculate node degree

            for(int i=0; i<=connectedNodes; i++)
            {
                totalDeg = totalDeg + deg[i];
            } // calculates total degre

        } while (deg[currentNode]<m); // the degree of node should be at least m

        currentNode = currentNode + 1; // we go to the next node
        connectedNodes = connectedNodes + 1;

        printf("%i connected nodes\n", connectedNodes);

    }while(connectedNodes<n);

    fprintf(output, "*Vertices %i\n", n);
    fprintf(output, "*edgeslist \n");

    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)

        if(matrix[i][j] != 0)
        {
            fprintf(output, "%i %i\n", i+1, j+1);
        }
    }

    for(int k = 0; k < n; k++)
    {
        fprintf(x, "%i\n", k+1);

        double counter = 0;

        for(int i = 0; i < n; i++)
        {
            if(deg[i] == k+1)
            {
                counter++;
            }
        }

        double probability = counter / n;

        fprintf(y, "%f \n", probability);

    }

    fclose(x);
    fclose(y);
    fclose(output);

}