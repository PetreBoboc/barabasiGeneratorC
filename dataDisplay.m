dataX = dlmread('x.txt', ' ', 0, 0);
dataY = dlmread('y.txt', ' ', 0, 0);

figure
plot(dataX, dataY, "*")
xlabel('k')
ylabel('P(k)')

figure
loglog(dataX, dataY, "*")
xlabel('k')
ylabel('P(k)')
