#include <iostream>

using namespace std;

int max_1d_range_mult(int* A, int n)
{
    int M[n + 1], S=1;
    int smax, smin;

    M[0] = 0;
    
    for (int i = 1; i <= n ; i++)
    {
         
         if (M[i] < 0)
         {
             M[i] = max(smax, M[i - 1]); 
             M[i] = min(smin, M[i + 1]); 
         }

    }


}

int main(void)
{
    int n=4;
    int A[n] = {-2, 4, 6, 3};
    
    cout<< max_1d_range_mult(A, n);

}