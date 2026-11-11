#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2000009;
ll c,t,n,d,x[N],ans,mi=N,cnt[5009][5009];
vector<ll> to[5009];
void dfs(ll x,ll vst,ll srt,ll fns){
	vst++;
	if(x==fns){
		if(vst<mi){
			mi=vst;
			cnt[srt][fns]=1;
			return;
		}
		if(vst==mi){
			cnt[srt][fns]++;
		}
		return;
	}
	if(to[x].size()==0){
		cnt[srt][fns]=0;
		return;
	}
	for(ll i=0;i<to[x].size();i++){
		if(to[x][i]>fns) break;
		dfs(to[x][i],vst,srt,fns);
	}
}
void solveBF(){
	for(ll i=1;i<=n;i++){
		for(ll j=i+1;j<=n;j++){
			if(x[j]-x[i]<=d){
				to[i].push_back(j);
				continue;
			}
			break;
		}
	}
	for(ll i=1;i<n-1;i++){
		for(ll j=i+2;j<=n;j++){
			mi=N;
			dfs(i,0,i,j);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	for(ll o=1;o<=t;o++){
		ans=0;
		scanf("%lld%lld",&n,&d);
		cout<<n<<" ";
		for(ll i=1;i<=n;i++){
			scanf("%lld",x+i);
		}
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++){
				cnt[i][j]=0;
			}
		}
		for(ll i=1;i<=n;i++){
			to[i]={};
		}
		if(1){
			solveBF();
			for(ll i=1;i<=n-2;i++){
				for(ll j=i+2;j<=n;j++){
					if(cnt[i][j]==2) ans++;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
} 
