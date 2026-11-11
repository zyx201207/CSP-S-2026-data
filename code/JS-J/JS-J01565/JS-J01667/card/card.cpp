#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5;
int n,m,a[N+5],ans[N+5],l[N+5],r[N+5],vis[N+5];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j<i){
                vis[j]=1;
            }else{
                vis[j]=0;
            }
        }
        for(int j=i;j<=n;j++){
            for(int p=i;p<j;p++){
                if(!vis[p] && a[p]==a[j]){
                    for(int q=p;q<j;q++){
                        vis[q]=1;
                    }
                }
            }
        }
        for(int j=1;j<=n;j++){
            if(!vis[j]){
                ans[a[j]]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout << ans[i] << " ";
    }
    return 0;
}