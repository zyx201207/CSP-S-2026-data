/*#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],ls[500005],top=0;
ll vis[300005];
ll tid[500005];
ll ans[500005];
ll fa[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        fa[tid[a[i]]=i;
        tid[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        top=0;
        for(int j=1;j<=m;j++){
            vis[j]=0;
        }
        for(int j=i;j<=n;j++){
            if(vis[a[j]]!=0){
                top=vis[a[j]];
            }
            else top++;
            vis[a[j]]=top;
            ls[top]=a[j];
        }
        for(int j=1;j<=top;j++){
            ans[ls[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005];
//ll vis[300005];
ll tid[500005];
ll ans[500005];
ll fa[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        fa[tid[a[i]]]=i;
        tid[a[i]]=i;
    }
    //cout<<fa[1]<<' '<<fa[2]<<' '<<fa[3]<<' '<<fa[4];
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            while(fa[j]!=0){
                j=fa[j];
                //cout<<1<<' ';
            }
            ans[a[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
