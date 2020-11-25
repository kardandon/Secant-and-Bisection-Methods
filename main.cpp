#include <bits/stdc++.h>
#include "Solution.cpp"
using namespace std;

int main(int argc, char* argv[])
{
	// We need at least 4 arguements (argc = 4 + 1 because the 1 is direction of the file)
	// an..a0 (n + 1 ( n>=0)), x0, x1, tolerance
    if (argc < 5)
    {
        cout << "Invalid number of args";
        return 1;
    }
    // Call solution class to solve the project
    Solution sol(argc - 4);
    // Load an..a0
    sol.load_args(argv);
    double x0, x1, tolerance;
    // Getting x0, x1, and tolerance value using stringstream
    stringstream s1(argv[argc - 3]);
    s1 >> x0;
    stringstream s2(argv[argc - 2]);
    s2 >> x1;
    stringstream s3(argv[argc - 1]);
    s3 >> tolerance;
    double x;
    unsigned long count;
    // Calculating using bisection
    count = sol.calc_bisection(x0, x1, tolerance, x);
    cout << "Using bisection" << endl;
    cout << "X = " << x << endl;
    cout << "Count = " << count << endl;
    // Calculating using secant
    count = sol.calc_secant(x0, x1, tolerance, x);
    cout << "Using secant" << endl;
    cout << "X = " << x << endl;
    cout << "Count = " << count << endl;
    // Calculating using hybrid
    count = sol.hybrid(x0, x1, tolerance, x);
    cout << "Using hybrid" << endl;
    cout << "X = " << x << endl;
    cout << "Count = " << count << endl;
    return 0;
}
