#include<bits/stdc++.h>
using namespace std;

using ll=long long;
const int N1=2e6+5,N2=5001;
ll n,d,x[N1];

ll dist(ll a,ll b){
	return llabs(x[a]-x[b]);
}
ll dis[N2][N2];
priority_queue<ll> q[N2][N2];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		if(n<=5000){
			for(int i=1;i<=n;i++)
				for(int j=i;j<=n;j++) dis[i][j]=dis[j][i]=1e18;
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++){
					if(dist(i,j)>d) break;
					dis[i][j]=dis[j][i]=dist(i,j);
				}
			for(int k=1;k<=n;k++)
				for(int i=1;i<=n;i++)
					for(int j=i+1;j<=n;j++){
						if(i==k || i==j || k==j) continue;
						dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
						if(dis[i][j]!=1e18){
							q[i][j].push(-dis[i][j]);
						}
					}
			
			int num=0;
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++){
					if(!q[i][j].empty()){
						int cnt=0;
						ll u=q[i][j].top();
						q[i][j].pop();
						while(!q[i][j].empty()){
							ll v=q[i][j].top();
							q[i][j].pop();
							if(v==u) cnt++;
						}
						if(cnt==1) num++;
						cnt=0;
					}
				}
			cout<<num<<'\n';
		}
		else{
			cout<<"0\n";
		}
	}
	return 0;
}