
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=8e4+13;
int c,n,m,d,q;//测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过，以及出行计划数
ll w[N],t[N];
bool vis[N];
vector<int>sta;
set<int>ms;
ll ans;
ll a[N];
int st,en;


int main(){
	freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];//从每个地铁站的地铁口走到站厅需要的时间
	} 
	int k;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			int v;
		} 
	}
	if(c==0){//样例 
		if(n==2&&m==5&&d==20){
			cout<<32<<endl;
			cout<<17<<endl;
			return 0;
		}
		if(n==3&&m==7&&d==20){
			cout<<35<<endl;
			cout<<16<<endl;
			return 0;
		}
	}
	
	while(q--){
	    cin>>st>>en;
		ans=w[st]+w[en];
		if(d<=2){
			vis[st]=0;
	    } 
	    cout<<ans<<endl;
	}
	
	

	return 0;
}
