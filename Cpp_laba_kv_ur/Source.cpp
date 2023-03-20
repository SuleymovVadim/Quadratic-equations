#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

void ReadFile(double& a, double& b, double& c)
{
    ifstream fin("input.txt");
    fin >> a >> b >> c;
    fin.close();
}

void WriteFile(double x1, double x2)
{
    ofstream fout("output.txt");
    if (isnan(x1) || isnan(x2))
    {
        fout << "No real roots found!" << endl;
    }
    else if (x1 == x2)
    {
        fout << "The equation has one root: " << x1 << endl;
    }
    else
    {
        fout << "The roots of the equation are: " << x1 << " and " << x2 << endl;
    }
    fout.close();
}

void SolveQuadraticEquation(double a, double b, double c, double& x1, double& x2)
{
    double discriminant = b * b - 4 * a * c;

    if (discriminant < 0)
    {
        x1 = x2 = NAN;
    }
    else if (discriminant == 0)
    {
        x1 = x2 = -b / (2 * a);
    }
    else
    {
        x1 = (-b + sqrt(discriminant)) / (2 * a);
        x2 = (-b - sqrt(discriminant)) / (2 * a);
    }
}

int main()
{
    double a, b, c, x1, x2;

    ReadFile(a, b, c);
    SolveQuadraticEquation(a, b, c, x1, x2);
    WriteFile(x1, x2);

    return 0;
}
