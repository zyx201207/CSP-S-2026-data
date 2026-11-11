#include<bits/stdc++.h>
using namespace std;
long long fyd[1023][1023];
int c,n,m,d,q;
int arr[500005];
void floyd_dp(){
	for(int i=1;i<=m;i++)fyd[i][i]=0;
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(fyd[i][k]!=4557430888798830399&&fyd[k][j]!=4557430888798830399){
					fyd[i][j]=min(fyd[i][j],fyd[i][k]+fyd[k][j]);	
				}
			}
		}
	}
}
pair<int,int>helpit[500005]; 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(fyd,0x3f,sizeof(fyd));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>arr[i];
	for(int i=1;i<=n;i++){
		int stt;cin>>stt;
		for(int j=1;j<=stt;j++)cin>>helpit[j].first>>helpit[j].second;
		for(int j=1;j<=stt;j++){
			for(int k=j+1;k<=stt;k++){
				long long dis=helpit[j].second+helpit[k].second;
				fyd[helpit[j].first][helpit[k].first]=min(fyd[helpit[j].first][helpit[k].first],dis);
				fyd[helpit[k].first][helpit[j].first]=min(dis,fyd[helpit[k].first][helpit[j].first]);
			}
		}
	}
	floyd_dp();
	while(q--){
		int u,v;cin>>u>>v;
		cout<<min(fyd[u][v],fyd[v][u])+arr[u]+arr[v]<<'\n';
	}
	return 0;
} 
