#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    long long int m,a[500002];
    scanf("%d %lld",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    if(n<=5000) sort(a+1,a+n+1);
    int maxi=1;
    for(int i=n;i>=maxi;i--)
    {
        long long int l=m;
        int s=1;
        while(l>=0)
        {
            l-=a[i]-a[i-s];
            s++;
        }
        maxi=max(maxi,s-1);
    }
   // for(int i=1;)
    printf("%d\n",maxi);
    return 0;
}//60
