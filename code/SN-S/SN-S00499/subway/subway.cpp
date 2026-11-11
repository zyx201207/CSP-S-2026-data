//左献科 西安市铁一中学 SN-S00499 
#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005],minn,r;
vector<pair<int,int> >v[550000];
bool b[550000];
void dfs(int x,int sum){
	if(sum>=minn)return ;
	if(x==r){
		minn=min(minn,sum);
		return ;
	}
	for(int i=0;i<v[x].size();i++){
		if(b[v[x][i].first]==0){
			b[v[x][i].first]=1;
			dfs(v[x][i].first,sum+v[x][i].second);
			b[v[x][i].first]=0;
		}
	}
}

signed main(){
//	ios::synm_whth_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int op,m,n,d,q;
	cin>>op>>m>>n>>d>>q;
//	cout<<endl;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++){
		int z,x,y;
		cin>>z;
		for(int j=1;j<=z;j++){
			cin>>x>>y;
			v[i+n].push_back({x,y});
			v[x].push_back({i+n,y});
		}
//		cout<<endl;
	} 
//	cout<<"\n\n\n"<<endl;;
//for(int i=1;i<=n+m;i++){
//	cout<<i<<':';
//	for(int j=0;j<v[i].size();j++){
//		cout<<v[i][j].first<<' ';
//	}
//	cout<<endl;
//}
	while(q--){
		for(int i=1;i<=n+m+1;i++){
			b[i]=0;
		}
		int x;
		minn=1000000000000001;
		cin>>x>>r;
		dfs(x,0);
		b[x]=1;
		cout<<minn+a[x]+a[r]<<'\n';
	}
}
