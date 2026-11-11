#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+7;
long long a[MAXN];
long long lst[MAXN];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n);
    for(int i=1;i<=n;i++)
    {
        lst[i]=a[i]+lst[i-1];
    }
    int l=1,r=0;
    while(r<=n)
    {
        if(a[r]*(r-l+1)-lst[r]+lst[l-1]>m){l++;r++;}
        else r++;
    }
    printf("%d",r-l);
    return 0;
}
/*
5 100
1 2 4 8 9
*/
