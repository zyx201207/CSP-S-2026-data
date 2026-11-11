#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define faster ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const int N=1e6+10,M=1e3+10,mod=1e9+7;
int c,T,n,d;
int x[N];
vector<int> vv;
void dfs(int u,int v,int len){
	if(u==v){
		vv.push_back(len);
		return ;
	}
	for(int i=u+1;i<=v;i++){
		if(abs(x[i]-x[u])<=d){
			dfs(i,v,len+abs(x[i]-x[u]));
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
//	faster;
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				dfs(i,j,0);
				sort(vv.begin(),vv.end());
				vv.clear();
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
