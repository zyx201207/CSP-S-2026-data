#include<bits/stdc++.h>
using namespace std;
int m,n,a[500005],b[300005];
long long c[300005];
stack<int> s;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        memset(b,0,sizeof(b));
        for(int j=i;j<=n;j++)
        {
            s.push(a[j]);
            if(b[a[j]]==0)
                b[a[j]]=j;
            else
            {
                for(int k=b[a[j]];k<j;k++)
                    s.pop();
            }
        }
        while(!s.empty())
        {
            int x=s.top();
            c[x]++;
            s.pop();
        }
    }
    for(int i=1;i<=m;i++)
        cout<<c[i]<<' ';
    return 0;
}
