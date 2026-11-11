#include<bits/stdc++.h>
using namespace std;
long long n,m,vis[300005],num[300005];
int main(){
    struct N{
        int s;
        int p;
    }a[500005];
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].s;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            vis[a[j].s]++;
            if(vis[a[j].s]==2)
            {
                for(int c=a[j].p;c<j;c++)
                {
                    if(vis[a[c].s]>0)vis[a[c].s]--;
                }
            }
            a[j].p=j;
        }
        for(int c=1;c<=m;c++)
            if(vis[c]==1)num[c]++;
    }
    for(int i=1;i<=m;i++)
        cout<<num[i]<<" ";
    return 0;
}
