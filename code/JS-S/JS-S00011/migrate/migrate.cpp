#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,t,c;
ll m,sum,a[2000005];
ll pd(int l,int r,int len,int ct)
{
    if(l==r&&ct==len)
        return 1ll;
    ll res=0;
    for(int i=l+1;a[i]-a[l]<=m&&i<=n;i++)
    {
        res+=pd(i,r,len,ct+1);
    }
    return res;
}
int sht(int l,int r,int ct)
{
    if(l==r)
        return ct;
    int nim=2e9;
    for(int i=l+1;a[i]-a[l]<=m&&i<=n;i++)
        nim=min(nim,sht(i,r,ct+1));
    return nim;
}
void sv()
{
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<n;i++)
    {
        for(int j=i+2;j<=n;j++)
        {
            int sh=sht(i,j,1);
            if(sh!=2e9&&pd(i,j,sh,1)==2)
            {
                sum++;
            }
        }
    }
    cout<<sum<<'\n';
    return;
}
void sv1(int l,int r)
{
    int lf=upper_bound(a+1,a+1+n,a[l]+m)-a-1;
    int ri=lower_bound(a+1,a+1+n,a[r]-m)-a;
    if(lf-ri+1==2)
        sum++;
    if(lf-ri<2)
        return;
    sv1(l+1,r);
    sv1(l,r-1);
    return;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>m;
        sum=0;
        if(n<=5000)
        {
            sv();
            continue;
        }
        bool f=1;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2])
                f=0;
        }
        if(f)
        {
            int j=a[n]-a[n-1];
            if(m>=2*j)
                cout<<max(0ll,n-(m/j*2-1))<<'\n';
            else
                cout<<"0\n";
        }
        else
        {
            sv1(1,n);
            cout<<sum<<'\n';
        }
    }
    return 0;
}
