#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
struct node{
	int to,s;
};
vector<node> tox[500001];
int dp[501][501];
int w[500001];
int read(){
	int out=0;
	char c=getchar();
	while(c<'0' || c>'9')c=getchar();
	while(c>='0' && c<='9')out*=10,out+=c-'0',c=getchar();
	return out;
}
void write(int x,bool sf){
	if(!x){
		if(sf)putchar('0');
		return;
	}
	write(x/10,0);
	putchar(x%10+'0');
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	cin>>c>>n>>m>>d>>q;
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++){
//		cin>>w[i];
		w[i]=read();
	}
	for(int i=1;i<=n;i++){
		int k;
//		cin>>k;
		k=read();
		for(int j=1;j<=k;j++){
			int a,t;
//			cin>>a>>t;
			a=read(),t=read();
			tox[a].push_back({i,t});
		}
	}
//	for(int i=1;i<=m;i++){
//		for(node j:tox[i]){
////			cout<<j.to<<' '<<j.s<<'|';
//		}
////		cout<<endl;
//	}
	memset(dp,0x3f,sizeof dp);
	for(int i=1;i<=n;i++)dp[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int j=0;j<tox[i].size();j++){
			for(int k=j+1;k<tox[i].size();k++){
				dp[tox[i][j].to][tox[i][k].to]=min(dp[tox[i][j].to][tox[i][k].to],tox[i][j].s+tox[i][k].s);
				dp[tox[i][k].to][tox[i][j].to]=min(dp[tox[i][k].to][tox[i][j].to],tox[i][j].s+tox[i][k].s);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<dp[i][j]<<' ';
//		}cout<<endl;
//	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int l,r;
//		cin>>l>>r;
		l=read(),r=read();
		int ans=LONG_LONG_MAX;
		for(node j:tox[l]){
			for(node k:tox[r]){
				ans=min(ans,j.s+k.s+dp[j.to][k.to]);
			}
		}
		ans+=w[l]+w[r];
//		cout<<ans+w[l]+w[r]<<endl;
		write(ans,1),putchar('\n');
	}
	return 0;
}
