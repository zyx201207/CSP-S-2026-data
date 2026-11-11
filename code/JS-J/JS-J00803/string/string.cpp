#include<bits/stdc++.h>
using namespace std;
int n;
long long zcx,ans,tot,x;
char y,zcy;
pair<long long,char> a[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    zcy='A';
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        cin>>y;
        if(zcy!=y)
        {
            a[tot++]={zcx,zcy};
            zcy=y;
            zcx=x;
        }
        else
            zcx+=x;
    }
    a[tot++]={zcx,zcy};
    if(tot==1)
        ans=0ll;
    else if(tot==2)
        ans=(long long)min(a[1].first,a[2].first);
    else
    {
        int i=1,j=tot-1;
        while(i<j)
        {
            if(a[i].second==a[j].second)
            {
                if(a[i].first!=a[j].first)
                {
                    int sss=abs(a[i].first-a[j].first);
                    if(a[i].first<a[j].first)
                    {
                        a[i+1].first-=sss;
                        ans+=sss;
                        a[i].first+=sss;
                    }
                    else
                    {
                        a[j-1].first-=sss;
                        ans+=sss;
                        a[j].first+=sss;
                    }
                }
            }
            else
            {
                if(a[i].first!=a[j].first)
                {
                    int sss=abs(a[i].first-a[j].first);
                    if(a[i].first<a[j].first)
                    {
                        a[i+1].first-=sss;
                        ans+=sss;
                        a[i].first+=sss;
                    }
                    else
                    {
                        a[j-1].first-=sss;
                        ans+=sss;
                        a[j].first+=sss;
                    }
                }
                ans+=a[i].first;
            }
            i++;
            j--;
        }
    }
    cout<<ans;
}
