#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in", " r" stdin)
    freopen("string.out", " w" stdout)
    int a;
    cin>>a;
    long long x[1000000005];
    long long n;
    char m;
    long long k=0;
    long long ans=0;
    for(int i=0;i<a;i++)
    {
        cin>>n;
        cin>>m;
        k+=n;
        for(long long j=0;j<n;j++)
        {
            x[ans]=m-'0';
            ans+=1;
        }
    }

    long long daan=0;
    if(k%2==0)
    {
        for(int i=0;i<k/2;i++)
        {
            if(x[i]!=x[k-i-1])
            {
                daan+=1;
            }
        }
    }
    else{
        for(int i=0;i<(k-1)/2;i++)
        {
            if(x[i]!=x[k-i-1])
            {
                daan+=1;
            }
        }
    }
    cout<<daan;
    return 0;
}