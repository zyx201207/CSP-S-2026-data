#include<bits/stdc++.h>
using namespace std;
long long a[10000000];
int main()
{
    long long n,m;
    cin>>n>>m;
    for(long long i=0;i<n;i++)
    {
        cin>>a[i];
    }
    long long sum=0;
    for(long long i=0;i<n;i++)
    {
        sum=max(a[i],a[i+1]);
    }
    while(sum>=2)
    {

    }
}
