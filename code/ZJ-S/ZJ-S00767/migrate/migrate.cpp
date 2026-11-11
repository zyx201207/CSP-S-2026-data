#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
int n,f[N],deq[N<<1],l,r;
ll x[N],d;
bool fg[N];
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;++i)cin>>x[i];
	int ans=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)f[j]=1e9,fg[j]=0;
		l=1,r=1,deq[1]=i,f[i]=0;
		int cnt=0;
		for(int j=i+1;j<=n;++j){
			while(l<=r&&x[j]-x[deq[l]]>d)++l;
			if(l>r)break;
if(((r-l==1&&f[deq[r]]==f[deq[l]])||(r-l>1&&f[deq[l+1]]==f[deq[l]]&&f[deq[l+2]]!=f[deq[l]]))&&(!fg[deq[l]]&&!fg[deq[l+1]]))++cnt,fg[j]=1;
if((r==l&&fg[deq[r]])||(r>l&&f[deq[l+1]]!=f[deq[l]]&&fg[deq[l]]))++cnt,fg[j]=1;
			f[j]=f[deq[l]]+1;
			while(l<=r&&f[deq[r]]>f[j])--r;
			deq[++r]=j;
		}
		ans+=cnt;
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
	int C,T;cin>>C>>T;while(T--)solve();
	return 0;
}
