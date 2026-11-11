#include<bits/stdc++.h>
using namespace std;
const int N=50;
int c,t,n,k,s[N],f[N],dis[N][N],d[N],ans;
bool us[N];
struct rod{
	int x,y;
}r[N];
int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
void dfs(int x,int cnt){
	if(x>n){
		if(cnt!=k) return;
		int _=0;
		for(int i=1;i<=n;i++)
			if(us[i]) s[++_]=i;
		memset(dis,0x3f,sizeof dis);
		for(int i=1;i<=n;i++) f[i]=i;
		for(int i=1;i<n;i++){
			int X=r[i].x,Y=r[i].y;
			dis[X][Y]=dis[Y][X]=1;
			if(!us[X]||!us[Y]) continue;
			int fx=find(X),fy=find(Y);
			if(fx!=fy) f[fx]=fy;
		}
		int cnt=0;
		for(int i=1;i<=n;i++)
			if(us[i]&&f[i]==i) cnt++;
		if(cnt>2) return;
		for(int e=1;e<=n;e++)
			for(int i=1;i<=n;i++){
				if(i==e) continue;
				for(int j=1;j<=k;j++){
					if(j==e||j==i) continue;
					int y=s[j];
					dis[i][y]=min(dis[i][y],dis[i][e]+dis[e][y]);
				}
			}
		memset(d,0x3f,sizeof d);
		int dd=0;
		for(int i=1;i<=n;i++){
			if(us[i]){
				d[i]=0;
				continue;
			}
			for(int j=1;j<=k;j++) d[i]=min(d[i],dis[i][s[j]]);
			dd=max(dd,d[i]);
		}
		ans=min(ans,dd);
		return;
	}
	us[x]=1;
	dfs(x+1,cnt+1);
	us[x]=0;
	dfs(x+1,cnt);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++) cin>>r[i].x>>r[i].y;
		ans=1e9;
		dfs(1,0);
		cout<<ans<<endl;
	}
	return 0;
}
