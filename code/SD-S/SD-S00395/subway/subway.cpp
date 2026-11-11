#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=5e5+10;
int c,n,m,d,q,w[N],a[510][510],t[510][510],k[510],f[N];//f[i],走到第i个地铁站的总代价 
vector<int> e[510];

int pb(int x,int pos){
	int b[510];
	for (int i=1;i<=k[pos];i++) b[i]=a[pos][i];
	return upper_bound(b+1,b+1+k[pos],x)-b;
}

void dfs(int x,int pos,int v){//x:目前站台编号，pos:目前是几号线
	f[pos]=min(f[pos],v);// ?
	int p=pb(x,pos);//
	if (p==k[pos] || pos>n) return;
	else p--;
	dfs(a[pos][p+1],pos,v);//不换乘 
	int q;
	for (int i=1;i<=n;i++){//枚举几号线 
		if (i==pos) continue;
		q=pb(x,i);
		if (q!=k[i]){
			q--;
			dfs(a[i][q+1],i,v+t[pos][x]+t[i][x]);
			if (q-1>0) dfs(a[i][q-1],i,v+t[pos][x]+t[i][x]);
		}
	}
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
		
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);

	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++){
		cin>>w[i];
	}
	for (int i=3;i<=n;i++){
		cin>>k[i-2];
		for (int j=1;j<=k[i-2];j++){
			cin>>a[i-2][j]>>t[i-2][j];
		}
	}
	int s,e;
	for (int i=1;i<=q;i++){
		cin>>s>>e;
		int cnt=0,ans=0;
		for (int j=1;j<=n;j++){
			int p=pb(s,j);
			if (p!=k[j]){
				dfs(s,j,0);
				ans=min(ans,f[e]+w[s]+w[e]);
			}
		}
		cout<<ans<<"\n";
	}
	
	return 0;	
}
