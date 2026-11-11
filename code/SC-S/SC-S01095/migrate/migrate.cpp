#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	char ch=getchar();
	int re=0,k=1;
	while('0'>ch||ch>'9'){
		if(ch=='-')k=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		re=re*10+(ch-'0');
		ch=getchar();
	}
	return re*k;
}
const int N=2e5+1e3;
int n,m,a[N],ans=0;
void dfs(int x,int y){
	queue<pair<int,int>>q;
	int as[n+1];
	memset(as,0,sizeof as);
	q.push({x,0});
	int bz=-1;
	for(;!q.empty();){
		pair<int,int>o=q.front();
		q.pop();
		int u=o.first,e=o.second;
		if(bz!=-1&&e>bz)break;
		if(u==y){
			if(bz==-1)bz=e;
			as[e]++;
			if(as[bz]>2)break;
			continue;
		}
		vector<pair<int,int>>ve;
		for(int i=u+1;i<=y&&a[i]-a[u]<=m;i++){
			ve.push_back({i,e+1});
		}
		for(int i=ve.size()-1;i>=0;i--){
			q.push(ve[i]);
		}
	}
	if(as[bz]==2)ans++;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=read(),K=read();
	while(K--){
		ans=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(c==11||c==12){
			if(m==1){
				cout<<0<<endl;
				continue;
			}
			cout<<max(n-(m+m-1),0ll)<<endl;
			continue;
		}
		for(int i=1;i<=n-3;i++){
			for(int j=i+3;j<=n;j++){
				dfs(i,j);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
