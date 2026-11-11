#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define repe(i,a,b) for(ll i = (a);i <= (b);i++)
#define rep(i,a,b) for(ll i = (a);i < (b);i++)
#define pb push_back

ll vis[600005];
ll cards[600005];
ll ar[600005];
ll n,m;
ll ans[600005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    repe(i,1,n){
        cin >> ar[i];
    }
    repe(i,1,n){
        repe(j,1,m) vis[j] = 0;
        repe(j,1,n) cards[j] = 0;
        ll cnt = 1;
        repe(j,i,n){
            if(vis[ar[j]]){
                repe(k,vis[ar[j]]+1,cnt){
                    vis[cards[k]] = 0;
                }
                cnt = vis[ar[j]];
            }else{
                cards[cnt] = ar[j];
                vis[ar[j]] = cnt;
                cnt++;
            }
        }
        repe(i,1,m){
            if(vis[i]) ans[i]++;
        }
    }
    repe(i,1,m){
        cout << ans[i] << ' ';
    }
    return 0;
}