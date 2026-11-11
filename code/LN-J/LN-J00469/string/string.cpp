#include<bits/stdc++.h>
using namespace std;
string b[2000000];
long long a[2000000],n;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
    }
    long long c = 1,sum = 0;
    while(n--)
    {
        while(a[n]>0)
        {
            if(a[c] >a[n])
            {
                if(b[c]!= b[n])
                {

                    sum+=a[n];
                }
                a[c]-=a[n];
                a[n] = 0;
            }
            if(a[c] <= a[n])
            {
               if(b[c]!= b[n])
               {
                   sum+=a[c];
               }
               long long m = a[c];
               a[c] = 0;
               c++;
               a[n]-=m;
            }
        }
    }
    cout << sum;
    return 0;
}
