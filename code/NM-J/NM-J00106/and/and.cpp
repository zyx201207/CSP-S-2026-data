#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000056];
int s[1000056];
int b[60];
int f(int x)
{
    if(x==0)
    {
        return 0;
    }
    for(int i=0;i<=30;i++)
    {
        int p=pow(2,i);
        int j=pow(2,i+1);
        if(x>=p && x<=j)
        {
            return i;
        }
    }
}
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int maxn=-1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        s[i]=f(a[i]);
        maxn=max(maxn,f(a[i]));
        b[f(a[i])]++;
    }
    long long ans=2147483647;
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=m;i++)
    {
        ans&=a[i];
    }
    cout<<ans;
    return 0;
}
