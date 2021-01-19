template <typename T, std::function<double(double)> T::f, std::function<double(double)> T::f_prime>
double newton_raphson(double initial, double threshold, const T& func)
{
    double y = func.f(initial);
    double x = initial;
    while (fabs(y) > threshold) {       
        x = x - func.f(x)/func.f_prime(x);
        y = func.f(x);
    }
    return x;
}

struct FuncPair {
    std::function<double(double)> f;
    std::function<double(double)> f_prime;

    FuncPair(std::function<double(double)> function, std::function<double(double)> derivative);            
    FuncPair(std::function<double(double)> function, double eps);
};

FuncPair::FuncPair(std::function<double(double)> function, std::function<double(double)> derivative)
    :f(function), f_prime(derivative)
{}

FuncPair::FuncPair(std::function<double(double)> function, double eps)
    :f(function)
{
    f_prime = [f, eps](double x) -> double {
        return (f(x+eps) - f(x))/eps;
    };
}
