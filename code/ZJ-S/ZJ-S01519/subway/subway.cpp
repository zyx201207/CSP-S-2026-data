#include<bits/stdc++.h>
using namespace std;

const int maxn=505;
const int maxm=5e5+5;
const long long inf=0x7f7f7f7f7f7f7f7f;

int n,m,d,q;
int w[maxm],k[maxn];

vector<int> a[maxn];
vector<int> t[maxn];
unordered_map<int,int> mp[maxn];

//struct node{
//	int a,t;
//};
//vector<node> a[maxn];

int cnt_dushu[maxm];
vector<int> vecc[maxm];

long long dis[maxn][maxn];

signed main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>n>>n>>m>>d>>q;	
	for(register int i=1;i<=n;i++){
		for(register int j=1;j<=n;j++){
			dis[i][j]=inf;
		}
		dis[i][i]=0;
	}
	for(register int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(register int i=1;i<=n;i++){
		cin>>k[i];
		a[i].resize(k[i]+2);
		t[i].resize(k[i]+2);
		for(register int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			mp[i][a[i][j]]=j;
			cnt_dushu[a[i][j]]++;
			vecc[a[i][j]].emplace_back(i);
		}
	}
	
	for(register int i=1;i<=m;i++){
		if(cnt_dushu[i]-1){
			register int qq=vecc[i].size();
			for(register int x=0;x<qq;x++){
				for(register int y=x+1;y<qq;y++){
				
				int ta=(long long)dis[vecc[i][x]][vecc[i][y]];
				int tb=(long long)t[vecc[i][x]][mp[vecc[i][x]][i]]+t[vecc[i][y]][mp[vecc[i][y]][i]];
				dis[vecc[i][x]][vecc[i][y]]=ta<tb?ta:tb;
				dis[vecc[i][y]][vecc[i][x]]=dis[vecc[i][x]][vecc[i][y]];
				
				}
			}
		}
	}
	
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<dis[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
	
	for(register int k=1;k<=n;k++){
		for(register int i=1;i<=n;i++){
			for(register int j=1;j<=n;j++){
				if(dis[i][k]+dis[k][j]<dis[i][j]){
					dis[i][j]=dis[i][k]+dis[k][j];
					dis[j][i]=dis[i][j];
				}
			}
		}
	}
	
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<dis[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
	
	for(register int i=1;i<=q;i++){
		register int u,v;cin>>u>>v;
		register long long ans=1e18;
		for(register int x:vecc[u]){
			for(register int y:vecc[v]){
				ans=ans<dis[x][y]+w[u]+w[v]+t[x][mp[x][u]]+t[y][mp[y][v]]?ans:dis[x][y]+w[u]
				+w[v]+t[x][mp[x][u]]+t[y][mp[y][v]];
			}
		}
		cout<<ans<<"\n";
	}
	
	return 0;
} 

/**
qiu qiu ni rang wo guo qv ba

subway7 wei shen me 1.005s

nazaban

bai lei yong yuan shi bai lei /ll


qiu qiu ni rang wo 7 gou ba wo shen me dou hui zuo de/ll
qiu qiu ni rang wo 7 gou ba wo shen me dou hui zuo de/ll
qiu qiu ni rang wo 7 gou ba wo shen me dou hui zuo de/ll
qiu qiu ni rang wo 7 gou ba wo shen me dou hui zuo de/ll
qiu qiu ni rang wo 7 gou ba wo shen me dou hui zuo de/ll
qiu qiu ni rang wo 7 gou ba wo shen me dou hui zuo de/ll
qiu qiu ni rang wo 7 gou ba wo shen me dou hui zuo de/ll
qiu qiu ni rang wo 7 gou ba wo shen me dou hui zuo de/ll
qiu qiu ni rang wo 7 gou ba wo shen me dou hui zuo de/ll
qiu qiu ni rang wo 7 gou ba wo shen me dou hui zuo de/ll
qiu qiu ni rang wo 7 gou ba wo shen me dou hui zuo de/ll
qiu qiu ni rang wo 7 gou ba wo shen me dou hui zuo de/ll
qiu qiu ni rang wo 7 gou ba wo shen me dou hui zuo de/ll
qiu qiu ni rang wo 7 gou ba wo shen me dou hui zuo de/ll
qiu qiu ni rang wo 7 gou ba wo shen me dou hui zuo de/ll
qiu qiu ni rang wo 7 gou ba wo shen me dou hui zuo de/ll
qiu qiu ni rang wo 7 gou ba wo shen me dou hui zuo de/ll
qiu qiu ni rang wo 7 gou ba wo shen me dou hui zuo de/ll
qiu qiu ni rang wo 7 gou ba wo shen me dou hui zuo de/ll
qiu qiu ni rang wo 7 gou ba wo shen me dou hui zuo de/ll
**/
