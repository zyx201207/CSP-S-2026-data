#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fori(a,b) for(int i=a; i<=b; i++)
#define forj(a,b) for(int j=a; j<=b; j++)
#define pii pair<ll,int>
#define mkpr make_pair
const int MAXN=2000005;
const ll INF=0x3f3f3f3f3f3f3f3f;
ll c,t,n,d;
bool __test=0;
ll x[MAXN];
int minn[MAXN],cnt[MAXN];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    while(t--){
        cin >> n >> d;
        fori(1,n){
            cin >> x[i];
        }
        ll ans=0;
        fori(1,n){
            memset(minn, 0x3f, sizeof(minn));
            memset(cnt, 0, sizeof(cnt));
            queue<pii> q;
            forj(i+1,n){
                if(x[j]-x[i]>d) break;
                q.push(mkpr(j,1));
            }
            while(!q.empty()){
                auto [a,b]=q.front();
                q.pop();
                if(minn[a]==INF) minn[a]=b,cnt[a]++;
                else if(b==minn[a]) cnt[a]++;
                forj(a+1,n){
                    if(x[j]-x[a]>d) break;
                    q.push(mkpr(j,b+1));
                }
            }
            forj(2,n){
                if(cnt[j]==2) ans++;
            }
        }
        cout << ans << "\n";
    }
}