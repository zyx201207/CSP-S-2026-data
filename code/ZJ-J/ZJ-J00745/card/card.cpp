#include<bits/stdc++.h>
#define int long long
using namespace std;
map<int ,int>sum,s;
signed main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    vector<int> b;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            sum[a[i]]=1;
            if(sum[a[i]]!=0)
            {
                int f=0;
                for(int k=0;k<b.size();k++)
                {
                    if(f==1)
                    {
                        sum[b[k]]=0;
                    }
                    if(b[k]==a[i])
                    {
                    	f=1;
					}
                }
            }
        }
        for(int k=0;k<b.size();k++)
        {
           s[b[k]]++;
        }
    }
    for(int i=0;i<m;i++)
    {
        cout<<s[m]<<" ";
    }
    return 0;
}
