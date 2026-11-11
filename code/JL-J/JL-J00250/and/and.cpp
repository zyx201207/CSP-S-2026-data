#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long long c[n];
    for(int i=0;i<=n;i++)
    {
        cin>>c[i];
    }
    long long maxn=-1;
    for(int i=0;i<=n;i++)
    {
        if(a[i]>=0){
            for(int j=i+1;j<=n;j++)
            {
                if(a[j]>=0)
                {
                    maxn=max(maxn,a[i]&a[j]);
                }
            }
        }
    }
    return 0;
}


