/**
 * @author      Kevin Mather <kmather73@gmail.com>
 * @version     0.1                 
 * @since       2015-11-08          
 */
 
 /**
 * Finds a root of the system f(x,y) = 0, g(x,y).
 *
 * @param epsilon  The desired error tolerance with respect to the L1 norm of f and g.
 * @param x        The initial starting value of x
 * @param y        The initial starting value of y
 * @param f        Pointer to the function f
 * @param f_x      Pointer to the x derivate of f
 * @param f_y      Pointer to the y derivate of f
 * @param g        Pointer to the function g
 * @param g_y      Pointer to the x derivate of g
 * @param g_x      Pointer to the y derivate of g
 * @return         void.
 */
 
void newtonRootFinding2D(const double epsilon, double &x, double &y, 
						double (*f)(double, double), double (*f_x)(double, double), double (*f_y)(double, double),
						double(*g)(double, double),double(*g_x)(double, double), double(*g_y)(double, double) )
{
	while(std::abs(f(x,y)) > epsilon && std::abs(g(x,y)) > epsilon){
		
		double det = f_x(x,y)*g_y(x,y) - f_y(x,y)*g_x(x,y);	

		double xn = x - (f(x,y) * g_y(x,y) - g(x,y) * f_y(x,y)) / det;	
		double yn = y - (g(x,y) * f_x(x,y) - f(x,y) * g_x(x,y)) / det;

		x = xn;
		y = yn;
	}
}
