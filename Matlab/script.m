clear;
clc;

hold on;
grid on;

T = [90 89 87 85 83 81 80 79 78 68 67 61 53 50 47 43 40 38 37]';
R = [180 162 211 230 199 184 196 200 200 285 280 330 408 450 500 600 620 660 670]';

T = T + 273.15;

plot(T, R, 'rx', 'markersize',10, 'linewidth', 2);

xlabel('Temparature (K)');
ylabel('Resistance (Ohms)');

y = log(R);
x = [(1./T), ones(length(T),1)];

c = inv(x'*x)*x'*y;
b = c(1);

T0 = 300;
R0 = exp(c(2) + (b/T0));

Te = 300:0.01:400;
Re = R0*exp(b*((1./Te) - (1/T0)));
plot(Te, Re, 'linewidth', 2);

fprintf('Results\n');
fprintf('R0 : %.2f\n', R0);
fprintf('b : %.2f\n', b);







