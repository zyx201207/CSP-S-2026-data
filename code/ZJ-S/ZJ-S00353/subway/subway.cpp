#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define MAXN 505
#define MAXM 500005
vector<int> lin[MAXN];//邻接表建图 
int m,n,c,d,q;
int t[MAXN][MAXM];//第n条线第m个站从站厅到站台的时间 
int w[MAXM];//地铁口到站厅的时间 
int k[MAXN];
int x,y;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i =1;i<=m;i++){
		cin>>w[i];
	}
	for(int i =1;i<=n;i++){
		cin>>k[i];
		int a,b,last;
		for(int j=1;i<=k[i];j++){
			cin>>a>>b;
			t[i][j]=b;
			if(j!=1){
				lin[last].push_back(a);
			}
			else{
				last=a;
			}
		}
	}
	for(int i =1;i<=q;i++){
		int ans;
		cin>>x>>y;
		ans+=w[x]+w[y];
		
		
		cout<<ans;
	}
	return 0;
}
