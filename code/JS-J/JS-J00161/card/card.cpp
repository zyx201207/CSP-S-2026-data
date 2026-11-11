# include <bits/stdc++.h>
# define int long long
using namespace std;
struct NODE{
    bool flag;
    int f;
};
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<int>a(n+10),b(m+10,0),f(m+10,0),ans(n+10,0);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int t=1;t<=n;t++){
        b.assign(m+10,0);
        f.assign(m+10,0);
        vector<int>card(n-t+1,0);
        int cnt=1;
        for(int i=t;i<=n;i++){
            if(b[a[i]]==1){
                for(int j=f[card[i]];j<=n-t+1;j++) card[j]=0;
            }
            card[cnt]=a[i];
            b[card[cnt]]=1;
            f[card[cnt]]=i;
            cnt++;
        }
        for(int i=1;i<=n-t+1;i++){
            for(int j=1;j<=m;j++){
                if(card[i]==j) ans[j]++;
            }
        }
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    return 0;
}
