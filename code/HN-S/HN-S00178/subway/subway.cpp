#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
int c,n,m,d,q,k;//测试点编号//地铁线//站//每个站最多被多少线过//出行计划  
int s,e,ans;
vector<pii> a(20001);//存k 
vector<int> wm;//站口to站厅
int dist[20001][20001];
int tmb,bmb;
void flyd(){
	for(int z=1;z<=m;z++){
		for(int i=1;i<=m;i++){
			if(dist[i][z]==inf){
				continue;
			}
			for(int j=1;j<=m;j++){
				if(dist[z][j]==inf){
					continue;
				}
				dist[i][j]=min(dist[i][j],dist[i][z]+dist[z][j]);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	wm.resize(m+1);
	for(int i=1;i<=m;i++){
		cin>>wm[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(i==j) {
				dist[i][j]=0;
		 	}
			else{
				dist[i][j]=inf;
			}
		}
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
		cin>>tmb>>bmb;
		a[j].first=tmb;//站台
		a[j].second=bmb;//时间 
		}
		for(int j=1;j<=k;j++){	
			for(int q=1;q<=k;q++){
				if(j==q) continue;
				dist[a[q].first][a[j].first]=min(a[j].second+a[q].second,dist[a[q].first][a[j].first]);
				dist[a[j].first][a[q].first]=min(a[j].second+a[q].second,dist[a[j].first][a[q].first]);
			}
		}
	}
	flyd();
	for(int i=1;i<=q;i++){
		cin>>s>>e;
		ans=dist[s][e];
		cout<<ans+wm[s]+wm[e]<<endl;
	}
	return 0;
}
