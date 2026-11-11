#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,T,n,k,sum,f[12][12],ans,cnt,head[1111],ji[11111];
struct no{
	int next,pre;
}a[11111111];
void add(int x,int y){a[++cnt]=(no){head[x],y};head[x]=cnt;}
void sc(int x,int fa,int d,int y){
	f[y][x]=d;
	for(int i=head[x];i;i=a[i].next){
		int sx=a[i].pre;
		if(sx==fa)continue;
		sc(sx,x,d+1,y);
	}
}
void check(int x,int fa,int co){
	for(int i=head[x];i;i=a[i].next){
		int sx=a[i].pre;
		if(sx==fa)continue;
		if(ji[sx]!=co&&co==0)sum++;
		check(sx,x,ji[sx]);
	}
}
void dfs(int x,int s){
	if(x>n){
		if(s!=k)return ;
		sum=ji[1];
		check(1,0,ji[1]);
		if(sum==2){
			int sss=0;
			for(int i=1;i<=n;i++){
				int ss=1111111111;			
				for(int j=1;j<=n;j++)
					if(ji[j]==1){
						ss=min(ss,f[i][j]);
					}
				sss=max(sss,ss);
			}
			ans=min(ans,sss);
		}
		return ;
	}
	ji[x]=1;dfs(x+1,s+1);
	ji[x]=0;dfs(x+1,s);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		int n,k;
		cin>>n>>k;
		int cnt=0;
		ans=1000000000;
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			add(x,y);
			add(y,x);
		}
		for(int i=1;i<=n;i++)
			sc(i,0,0,i);
		dfs(1,0);
		cout<<ans<<"\n";
	}
}
