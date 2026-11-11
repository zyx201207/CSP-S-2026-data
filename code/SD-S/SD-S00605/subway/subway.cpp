#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int ans=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		ans*=10;
		ans+=c-'0';
		c=getchar();
	}
	return ans*f;
}
int C,n,m,d,q;
struct node{
	int val,to,nxt;
}g[5005];
struct QwQ{
	int frm,val;
	bool operator < (const QwQ &p) const {
		return val>p.val;
	}
};
int h[2005];
int w[500005];
int dp[2005][2005];
bool fl[2005];
priority_queue<QwQ>s;
void dijks(int p){
	for(int i=1;i<=n+m;i++){
		fl[i]=0;
		dp[p][i]=0x3f3f3f3f;
	}
	dp[p][p]=0;
	s.push({p,0});
	while(!s.empty()){
		QwQ ttt=s.top();
		s.pop();
		if(fl[ttt.frm]){
			continue;
		}
		fl[ttt.frm]=1;
		dp[p][ttt.frm]=ttt.val;
		for(int i=h[ttt.frm];i!=0;i=g[i].nxt){
			if(!fl[g[i].to]){
				if(ttt.val+g[i].val<dp[p][g[i].to]){
					dp[p][g[i].to]=ttt.val+g[i].val;
					s.push({g[i].to,ttt.val+g[i].val});
				}
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		w[i]=read();
	}
	if(C>=1&&C<=6){
		for(int i=1;i<=n;i++){
			int k;
			k=read();
			for(int j=1;j<=k;j++){
				int a,t;
				a=read();
				t=read();
				dp[a][m+i]=t;
				dp[m+i][a]=t;
			}
		}
		for(int i=1;i<=n+m;i++){
			for(int j=1;j<=n+m;j++){
				if(i==j){
					dp[i][j]=0;
				}
				else if(dp[i][j]==0){
					dp[i][j]=0x3f3f3f3f;
				}
			}
		}
		for(int z=1;z<=n+m;z++){
			for(int i=1;i<=n+m;i++){
				for(int j=1;j<=n+m;j++){
					dp[i][j]=min(dp[i][j],dp[i][z]+dp[z][j]);
				}
			}
		}
		for(int i=1;i<=q;i++){
			int x,y;
			x=read();
			y=read();
			cout<<w[x]+w[y]+dp[x][y]<<endl;
		}
	}
	else if(C>=7&&C<=11){
		int pos=0;
		for(int i=1;i<=n;i++){
			int k;
			k=read();
			for(int j=1;j<=k;j++){
				int a,t;
				a=read();
				t=read();
				g[++pos]={t,a,h[m+i]};
				h[m+i]=pos;
				g[++pos]={t,m+i,h[a]};
				h[a]=pos;
			}
		}
		for(int i=1;i<=m+n;i++){
			dijks(i);
		}
		for(int i=1;i<=q;i++){
			int x,y;
			x=read();
			y=read();
			cout<<w[x]+w[y]+dp[x][y]<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
//fc /n subway.out subway3.ans
