//过了样例123 
#include<iostream>
#include<vector>
using namespace std;
#define int long long
const int maxn=505;
const int maxm=500005;
const int INF=2147483647;
int c=0,n,m,d,q;
int w[maxm];
struct sub{
	//k_i用a.size()表示 
	vector<signed> a;
	vector<int> t;
	int k(){
		if(a.size()==t.size())return a.size()-1;
		else {cout<<"Bug:a.size()!=t.size()\n";return -1;}
	}
};
vector<sub> subs;//以1为下标起始 
int pre_l_subs[maxn];
signed cnt_points[maxn];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>c>>n>>m>>d>>q;
	subs.resize(n+1);
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int n;
		cin>>n;
		subs[i].a.resize(n+1);
		subs[i].t.resize(n+1);
		for(int j=1;j<=n;j++)cin>>subs[i].a[j]>>subs[i].t[j];
		for(int j=1;j<=n;j++)cnt_points[subs[i].a[j]]++;
	} 
	pre_l_subs[0]=0;
	for(int i=1;i<=n;i++)
		pre_l_subs[i]=pre_l_subs[i-1]+subs[i].k();
		
	//
	vector<signed> find_points[maxn];//0为站厅，>0为站台
	find_points[0].resize(m+1);
	for(int i=0;i<=m;i++)
		find_points[0][i]=i;
	int lazy=0;
	for(int i=1;i<=n;i++){
		find_points[i].resize(subs[i].k()+1);
		find_points[1][0]=INF;
		for(int j=1;j<=subs[i].k();j++){
			if(cnt_points[subs[i].a[j]]==1){
				if(j>1){
					find_points[i][j]=find_points[i][j-1];
					continue;
				}
			}
			find_points[i][j]=m+pre_l_subs[i-1]+j-lazy;
		}
	}
	signed all_vpoints=find_points[n][find_points[n].size()-1];
//	cout<<all_vpoints;
//	for(int i=0;i<=n;i++){
//		for(int j=1;j<find_points[i].size();j++){
//			cout<<find_points[i][j]<<' ';
//		}
//	}
	//cout<<'\n';
	int dis[all_vpoints+1][all_vpoints+1];
	for(int i=0;i<=all_vpoints;i++){
		for(int j=0;j<=all_vpoints;j++){
			if(i==j)dis[i][j]=0;
			else dis[i][j]=INF/2;
		}
	}
	for(int i=1;i<=n;i++){
		int bef=1;
		for(int j=2;j<find_points[i].size();j++){
			dis[find_points[i][j]][find_points[i][j-1]]=dis[find_points[i][j-1]][find_points[i][j]]=0;
//			graph[find_points[i][j-1]].push_back(find_points[i][j]);
//			weight[find_points[i][j]].push_back(0);//奇怪，地铁内不消耗时间
//			weight[find_points[i][j-1]].push_back(0);//奇怪，地铁内不消耗时间
		}
		for(int j=1;j<find_points[i].size();j++){
			dis[find_points[i][j]][find_points[0][subs[i].a[j]]]=dis[find_points[0][subs[i].a[j]]][find_points[i][j]]=subs[i].t[j];
//			graph[find_points[0][subs[i].a[j]]].push_back(find_points[i][j]);
//			weight[find_points[i][j]].push_back(subs[i].t[j]);
//			graph[find_points[0][subs[i].a[j]]].push_back(subs[i].t[j]);
		}
	} 
	//建图,注意地铁口不是点 
	
	for(int i=1;i<=all_vpoints;i++)dis[i][i]=0;
	for(int k=1;k<=all_vpoints;k++){
		for(int i=1;i<=all_vpoints;i++){
			for(int j=1;j<=all_vpoints;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
//	for(int i=1;i<=all_vpoints;i++){
//		for(int j=1;j<=all_vpoints;j++){
//			cout<<dis[i][j]<<' ';
//		}
//		cout<<'\n';
//	}
//	
	
	for(int tititi=0;tititi<q;tititi++){
		int xr,yr;
		cin>>xr>>yr;
		//cout<<find_points[0][xr]<<' '<<find_points[0][yr]<<' '<<w[xr]<<' '<<w[yr]<<' ';
		cout<<w[xr]+w[yr]+dis[find_points[0][xr]][find_points[0][yr]]<<'\n';
	}
	
	
	return 0;
}
