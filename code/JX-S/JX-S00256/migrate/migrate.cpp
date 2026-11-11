#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(i) i<<1
#define rs(i) i<<1|1
#define lowbit(x) x&-x
const int N=5e3+10;
const int M=5e5+10;
const int base=1e9+7;
const int base1=1e9+9;
const int INF=0x3f3f3f3f3f3f3f3f;
int n,k;
int a[N];
int ans;
int c;
int r;
int cnt=INF;
int res=0;
void dfs(int pos,int now){
    if(pos==r){
        if(cnt<now) return;
        if(cnt==now){
            res++;
            return;
        }
        cnt=min(cnt,now);
        res=1;
        return;
    }
    if(now>cnt) return;
    for(int i=pos+1;i<=r;i++){
        if(a[i]-a[pos]<=k){
            dfs(i,now+1);
        }else{
            break;
        }
    }
}
void solve(){
    cin>>n>>k;
    ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int l=1;l<n;l++){
        for(r=l+1;r<=n;r++){
            bool ok=0;
            for(int i=l;i<r;i++){
                if(a[i+1]-a[i]>k){
                    ok=1;
                    break;
                }
            }
            cnt=INF;
            res=0;
            dfs(l,0);
            if(res==2){
                ans++;
            }
        }
    }
    cout<<ans<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>c;
	cin>>T;
	while(T--){
        solve();
	}
	return 0;
}
