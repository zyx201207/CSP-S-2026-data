#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N];
bool vis[N];
stack <long long> kkk;
long long ans[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        while(!kkk.empty()) kkk.pop();
        memset(vis,0,sizeof(vis));
        for(int j=i;j<=n;j++){
            long long cnt=a[j];
            if(vis[cnt]==0){
                kkk.push(cnt);
                vis[cnt]=1;
            }else{
                while(kkk.top()!=cnt){
                    vis[kkk.top()]=0;
                    kkk.pop();
                }
            }
        }
        for(int i=1;i<=m;i++){
            if(vis[i]==1) ans[i]++;
        }
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
    return 0;
}
