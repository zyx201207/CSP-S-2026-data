#include <bits/stdc++.h>
using namespace std;
const int N=5e3+10,inf=INT_MAX;

int a[N];
struct node{
	int v,w; 
};
vector<node> V[N];
int dis[N][N],ans[N][N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,t;
	cin>>c>>t;
	
	while(t--){
		for(int i=1;i<=N-5;i++){
		for(int j=1;j<=N-5;j++){
			dis[i][j]=inf;	
			ans[i][j]=0; 
		}
	}
		//cout<<"0\n";
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j){
					dis[i][j]=0;
					continue;
				}
				if(a[i]!=a[j]&&abs(a[i]-a[j])<=d)dis[i][j]=abs(a[i]-a[j]);
				if(a[i]!=a[j]&&abs(a[i]-a[j])<=d)dis[j][i]=abs(a[i]-a[j]);
				//cout<<dis[i][j]<<" ";
			}
			//cout<<"\n";
		}	
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(dis[i][k]!=inf&&dis[k][j]!=inf){
						if(dis[i][j]==inf)dis[i][j]=dis[i][k]+dis[k][j];
						if(dis[i][j]>=dis[i][k]+dis[k][j]){
							if(dis[i][j]==dis[i][k]+dis[k][j])ans[i][j]++;
							dis[i][j]=dis[i][k]+dis[k][j];
						}
					}
				}
			}
		}
		int pos=0;
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(ans[i][j]==2)pos++;
		cout<<pos<<"\n";
//0 2
//4 2
//1 2 3 4
//5 2
//1 2 3 4 5
	}

}

