#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int c,n,m,q,k,a,t,b[500010];
long long d[510][510],inf=1e18,ans;
vector<pair<int,int> >v[500010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&q,&q);
	//cout<<c<<n<<m<<q;
	for(int i=1;i<=m;i++)scanf("%d",&b[i]);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)d[i][j]=inf;
		d[i][i]=0;
		scanf("%d",&k);
		while(k--){
			scanf("%d%d",&a,&t);
			v[a].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<v[i].size();j++){
			for(int k=0;k<j;k++){
				d[v[i][k].first][v[i][j].first]=d[v[i][j].first][v[i][k].first]=min(d[v[i][j].first][v[i][k].first],1ll*v[i][j].second+v[i][k].second);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				d[j][k]=min(d[j][k],d[j][i]+d[i][k]);
			}
		}
	}
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<d[i][j]<<" ";
		}cout<<endl;
	}*/
	while(q--){
		cin>>a>>t;
		ans=inf;
		for(int i=0;i<v[a].size();i++){
			int p=v[a][i].first,q=v[a][i].second;
			for(int j=0;j<v[t].size();j++){
				int x=v[t][j].first,y=v[t][j].second;
				ans=min(ans,d[p][x]+b[a]+b[t]+q+y);
			}
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
