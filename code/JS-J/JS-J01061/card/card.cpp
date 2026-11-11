#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
int ans[500010];
bool vis[300010];
int s[500010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            vis[j]=false;
        }
        int p=0;
        for(int j=i;j<=n;j++){
            if(!vis[a[j]]){
                p++;
                s[p]=a[j];
                vis[a[j]]=true;
            }else{
                while(p!=0&&s[p]!=a[j]){
                    vis[s[p]]=false;
                    p--;
                }
            }
        }
        while(p!=0){
            ans[s[p]]++;
            p--;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
