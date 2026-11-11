#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,v1[50],d,a[210000],e[50];
string v[210000],k[210000];
bool cmp(string x,string y)
{
    if(x.size()!=y.size())return x.size()>y.size();
    else return x>y;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        d=0;
        while(a[i])
        {
           v[i]=char(a[i]%2+'0')+v[i];
           e[d]+=a[i]%2;
           a[i]/=2;
           d++;
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<v[i].size();j++)
        {
            if(e[(v[i].size()-1-j)]>=m)
            {
                k[i]+=v[i][j];
            }
        }
    }

    sort(k+1,k+1+n,cmp);

    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<k[i].size();j++)
        {
            if(k[i][j]=='0')continue;
            int kis=32,l=0;
            for(kis=32;kis>=1;kis--)
            {
                if(e[kis]>=m)
                {
                    l++;
                }
                if(l-1==j)break;
            }
            v1[kis]++;
        }
    }
    long long pp=1;
    for(int i=0;i<=32;i++)
    {
        if(v1[i]>=m)
        {
            //cout<<i<<endl;
            ans+=pp;
        }
        pp*=2;
    }

    cout<<ans<<endl;
    return 0;
}
