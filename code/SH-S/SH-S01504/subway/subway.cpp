#include <bits/stdc++.h>
using namespace std;
//地铁线路编号：1~n
//地铁站编号：n+1+
long long w[600010];
vector <pair<long long,long long> > o[600010];//原图<结点编号，距离> 
long long hyw[1000000];//这里不定义一个大数组就会322 
long long d[2000][2000];//缩完之后的图 
//void dfs(int x,int p){
//	
//} 
long long inf=1000000000000000000;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d1,q,v,t=0;//v是缩完之后的图的总结点数 
	long long n1,a,b,ans;
	cin >> c >> n >> m >> d1 >> q;
	for(int i=1;i<=2000;i++){
		for(int j=1;j<=2000;j++){
			d[i][j]=inf;
			if(i==j)d[i][j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cin >> w[i];
	}
	for(int i=1;i<=n;i++){
		cin >> n1;
		for(int j=1;j<=n1;j++){
			cin >> a >> b;
			o[i].push_back({a+n,b});
			o[a+n].push_back({i,b}); 
//			if(c<=6){
//				g[i]=i;
//				g[a+n]=a+n;
//				d[i][a+n]=b;
//				d[a+n][i]=b;
//			} 
		}
	}
	//if(c<=115 || c==22 || c==23){
		v=n;
		for(int i=n+1;i<=n+m;i++){
			for(int j=0;j<o[i].size();j++){
				for(int k=0;k<o[i].size();k++){
					d[o[i][j].first][o[i][k].first]=min(d[o[i][j].first][o[i][k].first],o[i][j].second+o[i][k].second);
				}
			}
		}	
	//}
//	for(int i=1;i<=v;i++){
//		for(int j=1;j<=v;j++){
//			cout << d[i][j] << ' ';
//		}
//		cout << endl;
//	}
//	if(c>=7 && c<=11){
//		for(int i=n+1;i<=n+m;i++){
//			if(o[i].size()!=1){
//				t++;
//				g[i]=t;
//			}
//		}
//		v=t;
//		for(int i=1;i<=n;i++){
//			if(g[o[i][0].first]!=0 && g[o[i][1].first]!=0){
//				d[g[o[i][0].first]][g[o[i][1].first]]=min(d[g[o[i][0].first]][g[o[i][1].first]],o[i][0].second+o[i][1].second);
//			}
//		}
//	}
//	if(c<=6){
//		v=n+m;
//	}
	for(int i=1;i<=v;i++){
		for(int j=1;j<=v;j++){
			for(int k=1;k<=v;k++){
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
				d[j][i]=min(d[j][i],d[j][k]+d[k][i]);
			}
		}
	}
//	for(int i=1;i<=v;i++){
//		for(int j=1;j<=v;j++){
//			cout << d[i][j] << ' ';
//		}
//		cout << endl;
//	}
	while(q--){
		ans=inf;
		cin >> a >> b;
//		if(c>=7 && c<=11){
//			ans=w[a]+w[b];
//			if(g[a]==0){
//				ans+=o[o[a][0].first][0].second+o[o[a][0].first][1].second;
//				a=o[o[a][0].first][1].first;
//			}
//			if(g[b]==0){
//				ans+=o[o[b][0].first][0].second+o[o[b][0].first][1].second;
//				b=o[o[b][0].first][1].first;
//			}
//			cout << ans+d[a][b];
//			continue;
//		}
		for(int i=0;i<o[a+n].size();i++){
			for(int j=0;j<o[b+n].size();j++){
				//cout << '#' << i << ' ' << j << ' ' << o[a+n][i].first << ' ' << o[b+n][j].first << ' ' << d[o[a+n][i].first][o[b+n][j].first] << endl;
				ans=min(ans,d[o[a+n][i].first][o[b+n][j].first]+o[a+n][i].second+o[b+n][j].second);
			}
		}
		cout << ans+w[a]+w[b] << endl;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2


0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3















*/
