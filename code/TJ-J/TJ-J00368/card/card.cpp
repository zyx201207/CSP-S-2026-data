#include<bits/stdc++.h>
using namespace std;
int n,m,a[500050],b[500050],de[500050],pm[300050];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        int t=1;
        for(int j=i;j<=n;j++)
        {
            de[t]=a[j];
            if(pm[a[j]]==0)
            {
                pm[a[j]]=t;
            }
            else
            {
                for(int k=t;k>pm[a[j]];k--)
                {
                    pm[de[k]]==0;
                    de[k]=0;
                }
                t=pm[a[j]];
            }
            t++;
        }
        for(int j=1;j<=n;j++)
        {
            if(de[j]!=0)
            {
                b[de[j]]++;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<b[i]<<" ";
    }
    return 0;
}
