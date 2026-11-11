#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,m;cin>>n>>m;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<vector<int>> b(n+1,vector<int>(31,0));
    for(int i=1;i<=n;i++) for(int j=30;j>=0;j--) b[i][j]=a[i]>>j&1;
    vector<int> cb(31);
    for(int i=0;i<=30;i++) for(int j=1;j<=n;j++) cb[i]+=b[j][i];
    vector<bool> cand(n+1,1);
    for(int i=30;i>=0;i--){
        if(cb[i]<m) continue;
        for(int j=1;j<=n;j++) if(!b[j][i]&&cand[j]){
            cand[j]=0;
            for(int k=i-1;k>=0;k--) cb[k]-=b[j][k];
        }
    }
    int ans=(1<<30)-1,res=m;
    for(int i=1;i<=n;i++) if(cand[i]&&res) ans&=a[i],res--;
    cout<<ans<<endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    solve();
    return 0;
}
