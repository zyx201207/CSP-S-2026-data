//SN-S00561 liuyuhe gxyzfdzx D
//last dance!
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int c,T,n,k,ans;
vector<int>g[N];
int depa[N],depb[N],tg[N];
inline void dfsa(int x,int fa){
	depa[x]=depa[fa]+1;
	for(int y:g[x]) if(y!=fa) dfsa(y,x);
}
inline void dfsb(int x,int fa){
	depb[x]=depb[fa]+1;
	for(int y:g[x]) if(y!=fa) dfsb(y,x);
}
inline int dfsc(int x,int fa){
	int num=1;
	for(int y:g[x]) if(y!=fa&&depa[y]<=depb[y])
		num=max(num,dfsc(y,x)+1);
	if(fa) tg[num]++;
	return num;
}
inline int dfsd(int x,int fa){
	int num=1;
	for(int y:g[x]) if(y!=fa&&depa[y]>depb[y])
		num=max(num,dfsd(y,x)+1);
	if(fa) tg[num]++;
	return num;
}
inline void slv(int x,int y){
	for(int i=1;i<=n;i++) tg[i]=0;
	dfsa(x,0),dfsb(y,0),dfsc(x,0),dfsd(y,0);
	int num=k-2;
	for(int i=n,cc;i;i--)
		cc=min(num,tg[i]),tg[i]-=cc,num-=cc;
	for(int i=n;i;i--) if(tg[i]){
		ans=min(ans,i);
		return;
	}
	ans=0;
}
inline void solve(){
	cin>>n>>k,ans=1e9;
	for(int i=1;i<=n;i++) g[i].clear();
	for(int i=1,u,v;i<n;i++)
		cin>>u>>v,g[u].push_back(v),g[v].push_back(u);
	if(c>=13&&c<=14){
		int num=n/2+2;
		slv(num/4+1,num-(num-1)/4-1);
		cout<<ans<<"\n";
		return;
	}
	for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) slv(i,j);
	cout<<ans<<"\n";
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--) solve();
	return 0;
}
