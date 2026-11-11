#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=5e5+5;
const int MAXM=3e5+5;
int a[MAXN];
int vis[MAXM];
ll c[MAXN];
ll s[MAXN];
int ans[MAXM];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        c[i]=i;
        s[i]=c[i]-c[i-1];
    }
    int p=0;
    for(int i=n;i>=1;i--){
        if(!vis[a[i]]){
            vis[a[i]]=i;
        }
        else{
            if(p!=0){
                s[vis[a[i]]]+=i;
                s[i+1]-=i;
                vis[a[i]]=i;
            }
            else{
            s[vis[a[i]]]+=i;
            s[i+1]-=i;
            vis[a[i]]=i;
            s[i+1]+=p;
            p=i;
            }
        }
    }
    for(int i=1;i<=n;i++){
        s[i]+=s[i-1];
    }
    for(int i=1;i<=n;i++){
        ans[a[i]]=s[i];
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
