#include<bits/stdc++.h>
using namespace std;
const int N =5e5+5;
int a[N];
int n,m;
int vis[N];
int to[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=n;i>=1;i--){
        to[i]=vis[a[i]];
        vis[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        if(to[i]==0){
            to[i]=i+1;
        }
    }
    memset(vis,0,sizeof vis);
    for(int i=1;i<=n;i++){
        int st=i;
        while(st<=n){
            if(to[st]==st+1&&a[to[st]]!=a[st]){
                vis[a[st]]++;
            }
            st=to[st];
        }
    }
    for(int i=1;i<=m;i++){
        printf("%d ",vis[i]);
    }
    return 0;
}
