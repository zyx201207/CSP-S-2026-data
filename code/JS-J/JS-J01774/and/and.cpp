#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
int a[MAXN];
int cnt[MAXN][35];
vector<int>v;
bool vis[MAXN];
bool cmp(int a,int b){
    return b>a;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        for(int j=31;j>=0;j--){
            if(a[i]&(1<<j)){
                cnt[i][j]++;
            }
        }
        vis[i]=1;
    }
    int ans=0;
    int ct=0;
    for(int i=31;i>=0;i--){
        int sum=0;
        for(int j=1;j<=n;j++){
            if(!vis[j])continue;
            if(cnt[j][i])sum++;
        }
        if(sum<m){
            continue;
        }
        for(int j=1;j<=n;j++){
            if(!vis[j])continue;
            if(!cnt[j][i]){
                vis[j]=0;
                ct++;
            }
        }
        if(n-ct>=m)ans+=(1<<i);
    }
    cout<<ans;
    return 0;
}
