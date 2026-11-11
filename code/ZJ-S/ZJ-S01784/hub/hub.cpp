#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;

int c,T,n,k,u[N],v[N],pl[N],ans,f[N],d[N],t,cnt,maxn;
vector<int>g[N];
void dfss(int nw,int fr,int fll){
	f[nw]=1;
	for(int wt:g[nw]){
		if(wt==fr)continue;
		if(fll==0&&d[wt]==0)continue;
//		if(d[wt]!=0)fl=0;
		d[wt]=min(d[wt],d[nw]+1);
		dfss(wt,nw,(d[wt]==0&&fll));
	}
}
void pd(){
//	for(int i=1;i<=k;i++){
//		cout<<pl[i]<<" ";
//	}
//	cout<<"\n";
	t=1;
	for(int i=1;i<=n;i++){
		f[i]=0;
		if(i==pl[t]){
			t++;
			d[i]=0;
		}else{
			d[i]=1e18;
		}
	}
	cnt=0;
	for(int i=1;i<=k;i++){
		if(f[pl[i]]==0){
			cnt++;
//			fll=1;
			dfss(pl[i],0,1);
		}
		if(cnt>2)return ;
	}
	maxn=0;
	for(int i=1;i<=n;i++){
		maxn=max(maxn,d[i]);
//		cout<<d[i]<<" ";
	}
//	cout<<"\n";
	ans=min(ans,maxn);
}
void dfs(int d,int st,int ct){
	if(ct==k){
		pd();
		return ;
	}
	if(st>n)return ;
	if(d==n+1)return ;
	for(int i=st;i<=n;i++){
		pl[d]=i;
		dfs(d+1,i+1,ct+1);
	}
}

//void dfs3(int nw,int fr){
//	d1[nw]=1;
//	for(int wt:g[nw]){
//		if(wt==fr)continue;
//		dfs(wt,nw);
//		if(d1[wt]+1>d1[nw]){
//			rss[nw]=wt;
//			d1[nw]=d1[wt]+1;
//		}
//	}
//}
//void rs(int nw){
//	nw=1;
//}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--){
		ans=1e18;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			g[i].clear();
//			lf[i]=0;
		}
		for(int i=1;i<n;i++){
			cin>>u[i]>>v[i];
			g[u[i]].push_back(v[i]);
			g[v[i]].push_back(u[i]);
		}
//		if(n<=10&&k<=10){
			dfs(1,1,0);
			cout<<ans<<"\n";
//		}
//		else{
//			dfs3(1,0);
//			for(int i:g[1]){
//				if(d1[i]>=maxx){
//					maxn=maxx;
//					maxx=d1[i];
//					m2=m1,m1=i;
//				}else if(d1[i]>=maxn){
//					maxn=d1[i];
//					m2=i;
//				}
//			}
//			rs(m1);
//			rs(m2);
////			for(int i=1;i<=n;i++){
////				if(lf[i]==1){
////					
////				}
////			}
//		}
//		cout<<"\n\n\n\n";
	}
	return 0;
}
