#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5,INF=1e7;
int C,T,n,k,f[N],g[N],dt[N];
vector<int> v[N];
int dfs(int x,int fa,int s){
	int as=0;
	if((s&(1<<x-1))&&(!(s&(1<<fa-1))||!fa))as++;
	for(int i:v[x]){
		if(i==fa)continue;
		as+=dfs(i,x,s);
	}
	return as;
}
int dfs2(int x,int fa,int s){
	if(s&(1<<x-1))return 0;
	int as=INF;
	for(int i:v[x]){
		if(i==fa)continue;
		as=min(as,dfs2(i,x,s)+1);
	}
	return as;
}
int ct;
void dfs3(int x,int fa,int s){
	dt[x]=dt[fa]+1;
	int mn=INF,mx=dt[x];
	for(int i:v[x]){
		if(i==fa)continue;
		dfs3(i,x,s);mx=max(mx,f[i]);
		mn=min(mn,g[i]);
	}
	if(mx-dt[x]+mn-dt[x]>s){
		if(mx-dt[x]==s)f[x]=dt[x]-1,g[x]=dt[x],ct++;
		else f[x]=mx,g[x]=mn;
	}
	else f[x]=dt[x],g[x]=mn;
}
bool ck(int x){
	ct=0;dfs3(1,0,x);
	return ct<=2;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>C>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)v[i].resize(0);
		for(int i=1,x,y;i<n;i++)cin>>x>>y,
		v[x].push_back(y),v[y].push_back(x);
		if(C<=3){
			int mn=INF;
			for(int s=0;s<(1<<n);s++){
				int ct=0;
				for(int i=1;i<=n;i++)if(s&(1<<i-1))ct++;
				if(ct>k)continue;
				if(dfs(1,0,s)>2)continue;
				int mx=0;
				for(int i=1;i<=n;i++)mx=max(mx,dfs2(i,0,s));
				mn=min(mn,mx);
			}
			cout<<mn<<'\n';
			continue;
		}
		if(k==2){
			int l=1,r=n,mid,as;
			while(l<=r){
				mid=l+r>>1;
				if(ck(mid))as=mid,r=mid-1;
				else l=mid+1;
			}
			cout<<as<<'\n';
		}
	}
} 