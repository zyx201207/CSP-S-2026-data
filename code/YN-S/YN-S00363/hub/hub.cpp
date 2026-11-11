#include <bits/stdc++.h>
using namespace std;
const int N=1000005;
vector <int> vt[N];
int hv[N],dis[N],n,k,cnt,mid;
bool dfs(int x,int fa){
	int pmx=x,phv=x;dis[x]=-1,hv[x]=n+1;
	for(int i:vt[x]){
		if(i==fa) continue;
		bool tmp=dfs(i,x);
		if(!tmp) return 0;
		if(hv[i]<hv[phv]) phv=i;
		if(dis[i]>dis[pmx]) pmx=i;
	}
	dis[x]=dis[pmx]+1,hv[x]=hv[phv]+1;
	if(phv!=pmx&&dis[x]+hv[x]<=mid) dis[x]=hv[x]-mid;
	if(dis[x]>=mid) cnt++,dis[x]=-mid,hv[x]=0;
	return cnt<=2;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,t,u,v;
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>u>>v;
			vt[u].push_back(v),vt[v].push_back(u);
		}
		int l=-1,r=n+1;
		while(l<r-1){
			mid=(r+l)/2;cnt=0;
			if(dfs(1,0)) r=mid;
			else l=mid;
		}
//		mid=1,cnt=0;
//		cout<<dfs(1,0)<<"\n";
		cout<<r<<"\n";
		for(int i=1;i<=n;i++) vt[i].clear();
	}
	return 0;
}
//lijiele tiaobuchulai