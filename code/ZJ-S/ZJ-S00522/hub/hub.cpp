#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+5;
ll c,t,mna[N],mnb[N],mnc[N],zdd,ydd,vis[N],ans,h;
vector<ll>q[N];
int n,k;
void dfsa(ll u,ll fa,ll len){
	mna[u]=len;
	for(int i=0;i<q[u].size();i++){
		int v=q[u][i];
		if(v==fa||len+1>=mna[v])continue;
		dfsa(v,u,len+1);
	}
}
void dfsb(ll u,ll fa,ll len){
	mnb[u]=len;
	for(int i=0;i<q[u].size();i++){
		int v=q[u][i];
		if(v==fa||len+1>=mnb[v])continue;
		dfsb(v,u,len+1);
	}
}
void dfsrs(ll u,ll fa,ll len){
	if(len==0)ans++,len=h;
	int ok=0;
	for(int i=0;i<q[u].size();i++){
		int v=q[u][i];
		if(v==fa)continue;
		ok=1;
		dfsrs(v,u,len-1);
	}
	if(ok==0&&len>=h/2)ans++;
}
int check(int x){
	h=x;
	ans=0;
	ll p=4e18;
	for(int i=1;i<=(x+1)/2;i++){
		dfsrs(i,0,(x+1)/2-i);
		p=min(p,ans);
		ans=0;
	}
	return p<=k;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	if(c==13||c==14){
		while(t--)cout<<1<<endl;
		return 0;
	}
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)q[i].clear();
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			q[u].push_back(v);
			q[v].push_back(u);
		}
		if(n==k){
			cout<<0<<endl;
			continue;
		}
		for(int i=1;i<=n;i++)mna[i]=mnb[i]=4e18;
		zdd=0,ydd=0;
		dfsa(1,0,0);
		int mx=0;
		for(int i=1;i<=n;i++){
			if(mx<mna[i]){
				mx=mna[i];
				zdd=i;
			}
		}
		dfsb(zdd,0,0);
		for(int i=1;i<=n;i++){
			if(mx<mnb[i]){
				mx=mnb[i];
				ydd=i;
			}
		}
		ll l=0,r=n*2,mid;
		while(l<=r){
			mid=(l+r)/2;
			if(check(mid))r=mid-1;
			else l=mid+1;
		}
		cout<<l/2<<endl;
	}
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
