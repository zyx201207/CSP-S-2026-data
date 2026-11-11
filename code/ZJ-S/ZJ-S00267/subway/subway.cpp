#include <bits/stdc++.h>
using namespace std;

namespace quick_io{
	template<typename T>
	void input(T &x){
		x=0;
		bool f=0;
		char ch=getchar();
		while(ch<'0'||ch>'9'){
			if(ch=='-') f=1;
			ch=getchar();
		}
		while(ch>='0'&&ch<='9'){
			x=x*10+ch-'0';
			ch=getchar();
		}
		if(f) x=-x;
	}
	
	template<typename T>
	void print(T x){
		if(x<0) putchar('-'),x=-x;
		if(x>=10) print(x/10);
		putchar(x%10+'0');
	}
}

using namespace quick_io;

#define int long long

const int N=550;
const int M=5e5+10;
const int Dis=30;
const int INF=1e16;

int c,n,m,D,q;
int w[M];

vector<pair<int,int>> r[M];
int d[N][N];

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	input(c);
	input(n);
	input(m);
	input(D);
	input(q);
	for(int i=1;i<=m;i++) input(w[i]);
	for(int i=1;i<=n;i++){
		int k;
		input(k);
		while(k--){
			int u,t;
			input(u);
			input(t);
			r[u].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			d[i][j]=INF;
	for(int i=1;i<=n;i++) d[i][i]=0;
	for(int i=1;i<=m;i++)
		for(auto u:r[i])
			for(auto v:r[i])
				d[u.first][v.first]=d[v.first][u.first]=min(d[v.first][u.first],v.second+u.second);
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	while(q--){
		int x,y;
		input(x);
		input(y);
		int ans=INF;
		for(auto u:r[x])
			for(auto v:r[y])
				ans=min(ans,w[x]+u.second+d[u.first][v.first]+v.second+w[y]);
		print(ans);
		putchar('\n');
	}
}