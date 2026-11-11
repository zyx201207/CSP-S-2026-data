#include<bits/stdc++.h>
using namespace std;
long long n,m,r=0,a[500005],vis[500005],tong[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){//lunshu
        for(int j=1;j<=r;j++)vis[j]=0;
        r=0;
        for(int j=i;j<=n;j++){//paishu
            bool f=0;
            for(int k=1;k<=r;k++)if(vis[k]==a[j]){r=k;f=1;}
            if(f==0)r++;
            vis[r]=a[j];

        }
        for(int j=1;j<=r;j++)tong[vis[j]]++;
    }
    for(int i=1;i<=m;i++)cout<<tong[i]<<" ";
    return 0;
}
