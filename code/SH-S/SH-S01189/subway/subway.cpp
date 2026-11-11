#include<bits/stdc++.h>
using namespace std;
int read(){
	int ret=0,w=1;
	char c=getchar();
	while(c<'0'||c>'9'){ 
		if(c=='-')w=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		ret=ret*10+c-'0';
		c=getchar();
	}
	return w*ret;
}
void write(long long x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
const int N=500015,NN=505;
long long W[N];
int c,n,m,d,q;
long long f[NN][NN];
struct node{
	int x;
	long long y;
};
vector<node>vec[N];
void chmin(long long &a,long long b){
	a=min(a,b);
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++)W[i]=read();
	for(int i=1;i<=n;i++){
		int k=read(),x,y;
		while(k--){
			x=read(),y=read();
			vec[x].push_back(node{i,y});
		}
	}
	memset(f,0x3f,sizeof f);
	node A,B;
	for(int i=1;i<=m;i++){
		for(int j=0;j<vec[i].size();j++){
			for(int k=j+1;k<vec[i].size();k++){
				A=vec[i][j],B=vec[i][k];
				chmin(f[A.x][B.x],A.y+B.y);chmin(f[B.x][A.x],A.y+B.y);
			}
		}
	}
	for(int i=1;i<=n;i++)f[i][i]=0;
	for(int x=1;x<=n;x++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				chmin(f[i][j],f[i][x]+f[x][j]);
			}
		}
	}
	while(q--){
		int A=read(),B=read();
		long long ans=1e18;
		for(auto x:vec[A]){
			for(auto y:vec[B]){
				chmin(ans,f[x.x][y.x]+x.y+y.y);
			}
		}
		ans+=W[A]+W[B];
		write(ans),putchar('\n');
	}
	return 0;
}
