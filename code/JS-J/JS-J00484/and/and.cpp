#include<bits/stdc++.h>
using namespace std;
int n,m;
struct nu
{
    int a,sum=0;
    string s;
}z[200005];
bool cmp(nu a,nu b)
{
    if(a.sum<b.sum)return 0;
    if(a.sum>b.sum)return 1;
    else
    {
        return a.a>b.a;
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>z[i].a;
        int j=30,ai=z[i].a;
        while(j--)
        {
            z[i].s+=(z[i].a%2+'0');
            if(z[i].a%2==1)z[i].sum++;
            z[i].a/=2;
        }
        z[i].a=ai;
    }
    sort(z+1,z+1+n,cmp);
    //for(int i=1;i<=n;i++)cout<<z[i].s<<'\n';
    int sum=z[1].a;
    for(int i=2;i<=m;i++)sum&=z[i].a;
    cout<<sum;
}
