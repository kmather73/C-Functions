/**
 * @author      Kevin Mather <kmather73@gmail.com>
 * @version     0.1                 
 * @since       2015-11-08          
 */
 
 /**
 * Finds a root of the function f(x).
 *
 * @param epsilon  The desired error tolerance with respect to the L1 norm of f and g.
 * @param xn        The initial starting value of x
 * @param f        Pointer to the function f
 * @param fPrime      Pointer to the derivate of f
 * @return         The found root.
 */
double newtonRootFinding(const double epsilon, double xn, double (*f)(double), double (*fPrime)(double)){
	double fOfx = f(xn);
	double fpOfx = fPrime(xn);
		
	while(true){
		if(std::abs(fOfx) < epsilon  ||  std::abs(fpOfx) < epsilon) //division by zero 
				break;
		xn = xn - fOfx / fpOfx;
		fOfx = f(xn);
		fpOfx = fPrime(xn);
	}
	return xn;
}
