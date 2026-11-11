#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=2e6+5;
int n,d,a[N];
int pre[N],suf[N];
int pr[N],sf[N];
int f[N],g[N];
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) pr[i]=sf[i]=0,f[i]=g[i]=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	queue<int> q;
	for(int i=1;i<=n;i++){
		q.push(i);
		while(q.size()&&a[i]-a[q.front()]>d) q.pop();
		pre[i]=q.front();
	}
	while(!q.empty()) q.pop();
	for(int i=n;i>=1;i--){
		q.push(i);
		while(q.size()&&a[q.front()]-a[i]>d) q.pop();
		suf[i]=q.front();
	}
	for(int i=1;i<=n;i++){
		f[i]++;
		if(suf[i]>i&&pre[suf[i]]==i) f[suf[i]]+=f[i];
		else if(suf[i]>i){
			int j=suf[i];
			if(pre[suf[j]]==j) f[suf[i]]++;
		}
		if(suf[i]>i) pr[suf[i]]++;
	}
	for(int i=n;i>=1;i--){
		g[i]++;
		if(pre[i]<i&&suf[pre[i]]==i) g[pre[i]]+=g[i];
		else if(pre[i]<i){
			int j=pre[i];
			if(suf[pre[j]]==j) g[pre[i]]++;
		}
		if(pre[i]<i) sf[pre[i]]++;
	}
//	for(int i=1;i<=n;i++) cout<<f[i]<<' '<<g[i]<<' '<<pr[i]<<' '<<sf[i]<<endl;
	int res=0;
	for(int i=2;i<=n;i++){
		bool fg=0;
		if(pre[i-1]==pre[i]&&pre[i-1]<i-1&&suf[i-1]==suf[i]&&suf[i]>i&&pre[suf[i]]==i-1&&suf[pre[i-1]]==i){
//			cout<<"! "<<i<<endl;
			res+=f[pre[i]]*g[suf[i]];
			fg=1;
		}
		bool f1=0,f2=0;
		if(pre[i-1]==pre[i]&&pre[i-1]<i-1&&suf[pre[i-1]]==i){
//			cout<<"!! "<<i<<' '<<f[pre[i]]*(sf[i-1]-fg)<<endl;
			res+=f[pre[i]]*(sf[i-1]-fg);
			if(!fg) f1=1;
		}
		if(suf[i-1]==suf[i]&&suf[i]>i&&pre[suf[i]]==i-1){
//			cout<<"!!! "<<i<<' '<<(pr[i]-fg)*g[suf[i]]<<endl;
			res+=(pr[i]-fg)*g[suf[i]];
			if(!fg) f2=1;
		}
//		cout<<"? "<<i<<' '<<(pr[i]-fg-f1)*(sf[i-1]-fg-f2)<<endl;
		if(suf[i-1]>i&&pre[i]<i-1) res+=(pr[i]-fg-f1)*(sf[i-1]-fg-f2);
	}
	cout<<res<<endl;
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int _,T;cin>>_>>T;while(T--) solve();
	return 0;
}
/*
rp++，想去WC/kel
*/