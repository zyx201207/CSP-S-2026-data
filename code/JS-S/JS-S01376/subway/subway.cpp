#include<bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+5;
int c,n,m,d,q,x,y,w[M];
bool flag[N];
long long ans,mx[M];
vector<int>a[N],t[N];
vector<pair<int,int> >b[M];
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){s=(s<<1)+(s<<3)+(ch-'0');ch=getchar();}
	return s*f;
}
inline void dfs(int dep,long long nowt,int now,int last){
	if(mx[now]<nowt)return;
	flag[last]=1;
	mx[now]=nowt;
	vector<pair<int,int> >::iterator it;
	for(it=b[now].begin();it!=b[now].end();it++){
		auto k=*it;
		int ft=k.first,sd=k.second;
		if(!flag[ft])
			for(int j=1;j<=a[ft][0];j++)
				dfs(dep+1,nowt+sd+t[ft][j],a[ft][j],ft);
	}
	flag[last]=0;
	return;
}
int main(){
	ios::sync_with_stdio(false);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();n=read();m=read();d=read();q=read();
	for(int i=1;i<=m;i++)w[i]=read();
	for(int i=1;i<=n;i++){
		a[i].push_back(read());
		t[i].push_back(a[i][0]);
		for(int j=1;j<=a[i][0];j++){
			a[i].push_back(read());
			t[i].push_back(read());
			b[a[i][j]].push_back({i,t[i][j]});
		}
	}
	while(q--){
		x=read();y=read();
		ans=w[x]+w[y];
		for(int i=0;i<=m;i++)mx[i]=LONG_LONG_MAX;
		dfs(0,ans,x,0);
		printf("%lld\n",mx[y]);
	}
	return 0;
}
