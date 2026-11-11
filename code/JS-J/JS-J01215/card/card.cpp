#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
queue<int> que;
long long a[2000010],vis[2000020],b[2000020];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];

    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            vis[a[i]]++;
            if(vis[a[i]]>1)
                for(int k=1;k<a[i];k++)vis[k]=0;
                vis[a[i]]=1;
        }
        for(int i=1;i<=n;i++){
            if(vis[i]==1)b[i]++;
        }
    }
    for(int i=1;i<=m;i++){
            cout<<b[i]<<endl;

    }
    return 0;
}
