#include<bits/stdc++.h>

using namespace std;

class Solution
{
    public:
    	// Constructor method using degree of the polinom
    	// x^n * an + ... + x^0 * a0 = f(x) n is degree
        Solution(int degree)
        {
        	// defining degree
            this->degree = degree;
            // allocate an array of coefficients
            coeffs = new double[degree];
        }
        // Destructor
        ~Solution()
        {
            delete[] coeffs;
        }
        // Loading coefficients from an char* array using stringstream
        void load_args(char* co[])
        {
            
            for (int i = 0; i < degree; i++)
            {
                stringstream ss(co[i + 1]);
                ss >> coeffs[i];
            }
        }
        // func(x) = x^n * an + ... + x^0 * a0
        double func(double x)
        {
            double sum = 0;
            for(int i = 0; i < degree; i++)
            {
                sum += coeffs[degree - 1 - i] * pow(x, i);
            }
            return sum;
        }
        // bisection algorythm
        short bisection(double x0, double x1, double tolerance)
        {
        	// middle value
            double p = x0 + (x1 - x0) / 2; 
            double r0 = func(x0);
            double r1 = func(p);
            double r2 = func(x1);
            // if middle value is close to ceiling or floor in terms of tolerance
            // it returns 0
            if( p - x0 <= tolerance)
            {
                return 0;
            }
            else if (x1 - p <= tolerance)
            {
                return 0;
            }
            else
            {
            	// if f(x0) and f(p) has different signs return -2
                if(r0 < 0 ^ r1 < 0)
                {
                    return -2;
                }
                // if f(p) and f(x1) has different signs return 2
                else if (r1 < 0 ^r2 < 0)
                {
                    return 2;
                }
                // if something goes wrong (there is not any root in that interval)
                else
                {
                    return 3;
                }
            }
        }
        // calculating root and count using bisection
        // this method returns iteration count
        unsigned long calc_bisection(double x0, double x1, double tolerance, double& x)
        {
            unsigned long count = 1;
            short res = bisection(x0, x1, tolerance);
            // res will be 2 or -2 if it is between x0 - p or p - x1
            while(abs(res) == 2)
            {
            	// if it is near to x0 -> x1 = p
                if (res == -2)
                {
                    x1 = x0 + (x1 - x0) / 2;
                }
                // if it is near to x1 -> x0 = p
                else if (res == 2)
                {
                    x0 = x0 + (x1 - x0) / 2;
                }
                // rerun that algorithm
                res = bisection(x0, x1, tolerance);
                count++;
            }
            // if something goes wrong (there is not any root in that interval)
            if (res == 3)
                return 0;
			// if all goes well x = p (x is the adress)
            else if(res == 0)
                x = x0 + (x1 - x0) / 2;
            return count;
        }
        // secant algorythm
        double secant(double x0, double x1)
        {
            double fx1 = func(x1);
            double fx0 = func(x0);
            // it returns the result of secant algorythm iteration
            return x1 - (fx1 * (x1 - x0)) / (fx1 - fx0);
        }
        // calculating root and count using secant method
        // this method returns iteration count
        unsigned long calc_secant(double x0, double x1, double tolerance, double& x)
        {
            unsigned long count = 0;
            // iterating while absolute difference is not less then tolerance value
            while(!(abs(x1 - x0) < tolerance))
            {
            	// x is the adress
                x = secant(x0, x1);
                x0 = x1;
                x1 = x;
                count++;
            }
            return count;
        }
        // calculating root and count using 2 iterations of bisection and some iterations of secant method
        // this method returns iteration count
        unsigned long hybrid(double x0, double x1, double tolerance, double& x)
        {
            unsigned long count = 0;
            short res;
            // iterating while count != 2
            while (count != 2)
            {
                count++;
                res = bisection(x0, x1, tolerance);
                // if it is near to x0 -> x1 = p
                if(res == -2)
                {
                    x1 = x0 + (x1 - x0) / 2;
                }
                // if the root is found returns count
                else if (res == 0)
                {
                    x = x0 + (x1 - x0) / 2;
                    return count;
                }
                // if it is near to x1 -> x0 = p
                else if (res == 2)
                {
                    x0 = x0 + (x1 - x0) / 2;
                }
                else
                    return 0;
            }
            // after using bisection we find the root using the values we got from
            // bisection method using secant method
            return count + calc_secant(x0, x1, tolerance, x);
        }
    private:
    	// coefficient array
        double* coeffs = NULL;
        // degree of polinomial
        int degree;
};
