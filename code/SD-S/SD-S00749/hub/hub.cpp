#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	char c=getchar();
	long long x=0,f=1;
	while(c>'9'||c<'0'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+(c-'0');
		c=getchar();
	}
	return x*f;
}
inline void write(long long x){
	if(x<0){
		putchar('-');
		write(-x);
		return ;
	}
	if(x>9){
		write(x/10);
	}
	putchar(x%10+'0');
	return ;
}
const int N=1e6+5;
const int INF=1e9+7;
int n,k,C,T,x,y,ans;
vector<int> a[N];
int vis[N];
int f[N];
int dis[305][305];
int Find(int x){
	if(x==f[x]){
		return x;
	}
	return f[x]=Find(f[x]);
}
void fun(){
	for(int i=1;i<=n;i++){
		if(vis[i]==1){
			f[i]=i;
		}
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			continue;
		}
		for(int j=0;j<a[i].size();j++){
			int x=a[i][j];
			if(vis[x]==0){
				continue;
			}	
			int fx=Find(i),fy=Find(x);
			if(fx!=fy){
				f[fx]=fy;
			}
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(vis[i]==1&&f[i]==i){
			cnt++;
		} 
	}
	if(cnt!=2){
		return ;
	}
	int maxx=0,d;
	for(int i=1;i<=n;i++){
		d=0x3f3f3f3f;
		for(int j=1;j<=n;j++){
			if(vis[j]){
				d=min(d,dis[i][j]);
			}
		}
		maxx=max(maxx,d);
	}
	ans=min(ans,maxx);
	return ;
}
void dfs(int x,int cnt){
	if(cnt>k){
		return ;
	}
	if(x==n+1){ 
		if(cnt==k){
			fun();
		} 
		return ;
	}
	vis[x]=1;
	dfs(x+1,cnt+1);
	vis[x]=0;
	dfs(x+1,cnt); 
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	C=read(),T=read();
	while(T--){
		n=read(),k=read();
		memset(dis,0x3f,sizeof(dis));
		for(int i=1;i<=n;i++){
			dis[i][i]=0;
		}
		for(int i=1;i<n;i++){
			x=read(),y=read();
			a[x].push_back(y);
			a[y].push_back(x);
			dis[x][y]=1;
			dis[y][x]=1;
		}
		ans=0x3f3f3f3f;
		if(n<=10){
			for(int k=1;k<=n;k++){
				for(int i=1;i<=n;i++){
					for(int j=1;j<=n;j++){
						dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
					}
				}
			}
			dfs(1,0);
			cout<<ans<<"\n";
			continue; 
		}
		cout<<((n+1)/2-k+2)/4+2<<"\n";
	}
	return 0;
} 
