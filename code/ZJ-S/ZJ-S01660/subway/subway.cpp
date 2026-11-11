#include<bits/stdc++.h>
using namespace std;
const int N=5000;
int c,n,m,d,T;
int s[N],a[N][N];
int f[N][N],cnt;
int v[N][N],ans;
struct subway{
	int to;
	int time;
} way[N];
void dfs(int st,int en){
	if(st==en){
		ans=max(ans,cnt);
		return;
	} 
	if(v[st][en]!=0){
		cnt+=v[st][en];
		ans=max(ans,cnt);
		return;
	}
	for(int i=1;i<=m;i++){
		if(f[st][i]!=-1){
			int x=cnt;
			cnt+=f[st][i];
			dfs(i,en);
			v[i][en]=cnt-x;
			cnt=x;
		} 
	}
	return;
}
void solve(){	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int st,en;
	cin>>st>>en;
	cnt=0,ans=INT_MIN;
	dfs(st,en);
	cout<<ans+s[st]+s[en]<<"\n";
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>T;
	for(int i=1;i<=m;i++) cin>>s[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int stop,cost;
			cin>>stop>>cost;
			way[i].to=stop;
			way[i].time=cost;
			a[stop][++a[stop][0]]=i;
		} 
	}
	for(int i=1;i<=m;i++) for(int j=1;j<=m;j++) f[i][j]=-1;
	for(int i=1;i<=m;i++){
		int len=a[i][0];
		for(int j=1;j<=len;j++){
			int go=way[a[i][j]].to;
			if(i==go) continue;
			f[i][go]=way[i].time+way[go].time;
			f[go][i]=f[i][go];
		}
	}
	while(T--) solve();
	return 0;
}