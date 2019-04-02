%input
%data = [1;2;3;4;5;6;7;8;9;10];
%costo = [2;2;2;4;4;6;6;6;10;10];
x = rand(100,1)*16 - 8;
y = rand(100,1)*16 - 8;
r = sqrt(x.^2 + y.^2) + eps;
z = sin(r)./r;
data = [x,y];
costo = z;
m = size(data,1);
cant_componentes = size(data,2);
%umbral = 0.5;
%alpha = 0.005;
umbral = 0.05;
alpha = 0.0005;

%X
X = ones(m,1+cant_componentes);
for c = 1 : cant_componentes
    for f = 1: m
        X(f,c+1) = data(f,c);
    end
end

%theta
theta = zeros(cant_componentes,1);
for f = 1 : cant_componentes + 1
    theta(f,1) = rand;
end

%h(X)
h = X*theta;

%error
errors = (h - costo).^2;
error = sum(errors)/(2*m);

while(error>umbral)
    for f = 1:size(theta,1)
        theta(f,1) = theta(f,1) - alpha * ( sum( (h-costo).*X(:,f) ) /m);
    end
    h = X*theta;
    errors = (h - costo).^2;
    error = sum(errors)/(2*m);
end

subplot(1,1,1);
%plot(data,costo,'o',data,h);
plot3(data(:,1), data(:,2), costo,'o',data(:,1), data(:,2),h,'o');






