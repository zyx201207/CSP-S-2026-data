#include<bits/stdc++.h>
using namespace std;
int a[500005],ans[500005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,sum=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        vector<int> s(n+1);
        int len=0;
        for(int j=i;j<=n;j++)
        {
            for(int k=len;k<s.size();k++)
            {
                if(s[k]==a[j])
                {
                    len=k+1;
                    break;
                }
            }
            s.push_back(j);
        }
        for(int i=1;i<=m;i++)
        {
            for(int j=len;j<s.size();j++)
            {
                if(s[j]==m)
                {
                    ans[m]++;
                    break;
                }

            }
        }

    }
    for(int i=1;i<=m;i++) cout<<ans[m]<<' ';
    return 0;
}
