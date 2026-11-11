#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int> g[32];
int tot[32];
int a[200006];
int vis[200006];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        int x=31;
        while(x--){
            if(a[i]&(1<<x)) g[x].push_back(i),tot[x]++;
        }
    }
    int j=30;
    while(tot[j]<m&&j>=0) j--;
    if(j==-1){
        cout<<0;
        return 0;
    }
    int ans=(1<<j);
    for(auto i:g[j]){
        vis[i]=1;
    }
    int tmpj=j;
    while(j){
        j--;
        int cnt=0;
        for(auto i:g[j]){
            if(vis[i]==tmpj-j){cnt++;vis[i]++;}
        }
        if(cnt<m){
            break;
        }
        ans+=(1<<j);
    }
    cout<<ans;
    return 0;
}