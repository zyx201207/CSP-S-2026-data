#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
signed w[500001],x[100001],y[100001],tim[501][500001];
vector<signed> e[500001],a[501],t[501];
bool b[500001];
int sj(int begin,int end,int from){
	if(begin==end) return 0;
	b[begin]=1;
	int minn=0xffffffff;
	for(auto i:e[begin]){
		if(i==from) continue;
		for(auto j:a[i]){
			if(b[j]) continue;
			b[j]=1;
			minn=min(sj(j,end,i)+tim[i][begin]+tim[i][j],minn);
			b[j]=0;
		}
	}
	b[begin]=0;
	return minn;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int x,y,z;
		cin>>x;
		while(x--){
			cin>>y,a[i].push_back(y);
			e[y].push_back(i);
			cin>>z,t[i].push_back(z);
			tim[i][y]=z;
		}
	}
	for(int i=1;i<=q;i++)cin>>x[i]>>y[i];
	for(int i=1;i<=q;i++){
		memset(b,0,sizeof(b));
		cout<<w[x[i]]+w[y[i]]+sj(x[i],y[i],0)<<endl;
	}
	return 0;
}
