#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,tzk;
int a[200005],c[200005];
int ans[200005],vis[200005],cnt[200005];
void teyi(){
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(a[j+1]!=a[j])vis[a[j]]=1;
            else vis[a[j]]=0;
        }
        for(int j=1;j<=m;j++){
            if(vis[j]==1)ans[j]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    cin>>n>>m;
    bool flag=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i!=1&&a[i]>a[i-1])flag=1;
    }
    if(flag==0)teyi();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            c[j]=0;
        }
        for(int j=1;j<=2*m;j++){
            vis[j]=0;
        }
        tzk=0;
        for(int j=i;j<=n;j++){
            if(vis[a[j]]==0){
                vis[a[j]]=++tzk;
                c[tzk]=a[j];
            }
            else{
                int tzn=vis[a[j]]-1;
                for(int k=vis[a[j]];k<=tzk;k++){
                    vis[c[k]]=0;
                    c[k]=0;
                }
                tzk=tzn;
                vis[a[j]]=++tzk;
                c[tzk]=a[j];
            }
        }
        for(int j=1;j<=tzk;j++){
            cnt[c[j]]=1;
        }
        for(int j=1;j<=m;j++){
            if(cnt[j]==1)ans[j]++;
            cnt[j]=0;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
	return 0;
}
