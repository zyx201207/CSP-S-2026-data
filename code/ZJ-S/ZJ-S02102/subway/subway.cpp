#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		x=x*10+ch-48;
		ch=getchar();
	}
	return f*x;
}
#define int long long
int c,n,m,d,q;
const int M=5e5+6,N=506;
int w[M];//gate to hall
int t[N][M];
int dis[M][M];
int x,y;
vector<int> line;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		w[M]=read();
	if(c>=12 && c<=19){
		while(q--){
			int ans;
			cin>>x>>y;
			ans=w[x]+w[y];
			
		}
	}
	if(c>=7 && c<=11){
		for(int i=1;i<=n;i++){
			int k,ww,www;
			k=read();
			if(k==1) cin>>ww>>www;
			else{
				cin>>x>>t[k][x]>>y>>t[k][y];
				
			}
		}
		
	}
	return 0;
}