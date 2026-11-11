#include<bits/stdc++.h>
using namespace std;

const int N=1e6+5;
int n,k,md[N],col[N];
vector<int> e[N];

void dfs(int x,int fa){
	for(int i:e[x]){
		if(i==fa) continue;
		dfs(i,x);
		md[x]=max(md[x],md[i]+1);
	}
}
int qwq=0;
void ddfs(int x,int fa,int d,int k,int mx){
	if(mx>k) return;
	int c=0;
	for(int i:e[x]){
		if(i==fa) continue;
		c+=col[i];
	}
	if(c==1){
		for(int i:e[x]){
			if(i==fa) continue;
			if(md[i]+d<k) continue;
			if(col[i]) continue;
			mx=max(mx,md[i]+1);
		}
		if((d<=k&&!mx)||mx+1<=k){
//			cout<<"! "<<mx<<endl;
			qwq++;
			for(int i:e[x]){
				if(i==fa) continue;
				if(col[i]){
					if(d<=k&&!mx) ddfs(i,x,d+1,k,mx);
					else ddfs(i,x,d+1,k,mx+1);
				}
			}
		}
	}
}

bool check(int x){
//	cout<<x<<endl;
	for(int i=1;i<=n;i++){
		//i为根
		for(int j=1;j<=n;j++) md[j]=col[j]=0;
//		cout<<"chk "<<i<<endl;
		dfs(i,0);
		for(int j=1;j<=n;j++) if(md[j]>=x) col[j]=1;
		col[i]=1;
//		for(int j=1;j<=n;j++) cout<<md[j]<<' ';cout<<endl;
//		for(int j=1;j<=n;j++) cout<<col[j];
//		cout<<endl;
		int cnt=0;
		for(int j=1;j<=n;j++) if(col[j]) cnt++;
		int c=0;
		for(int j:e[i]){
			qwq=0;
			ddfs(j,i,1,x,0);
//			cout<<"! "<<i<<' '<<j<<' '<<qwq<<endl;
			c=max(c,qwq);
		}
		if(cnt-c<=k) return 1;
	}
//	cout<<"tzsb"<<endl;
	return 0;
}

void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++) e[i].clear();
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	int l=-1,r=n+1;
	while(l+1<r){
//		cout<<"! "<<l<<' '<<r<<endl;		
		int mid=l+r>>1;
		if(check(mid)) r=mid;
		else l=mid;
	}
	cout<<r<<endl;
}

signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int _,T;cin>>_>>T;while(T--) solve();
	return 0;
}
/*
rp++，想去WC/kel
*/