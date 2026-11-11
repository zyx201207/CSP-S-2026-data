#include <bits/stdc++.h>
using namespace std;
int ans=0;
int minn=1000000000;
void mj(vector<int> vc,vector<int> dis,int s,int p,int d){
		for(int i=s;i<p;i++){
			if(vc[i]+d>=vc[p]){
				minn=min(minn,dis[i]+1);
				dis[p]=minn;	
			}
		}
		int cnt=0;
		for(int i=s;i<p;i++){
	
				if(dis[i]+1==minn) cnt++;
			
		}
		dis[p]=minn;
		if(cnt==2){
			ans++;	
		}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		ans=0;
		int n,d;
		cin>>n>>d;
		minn=100000000;
		vector<int> island(n+5);
		vector<int> dis(n+5);
		for(int i=1;i<=n;i++){
			dis[i]=20000000;
		}
		for(int i=1;i<=n;i++){
			cin>>island[i];
		}
		dis[0]=0;
		dis[1]=0;
		for(int j=1;j<=n;j++){
			for(int i=1;i<=n;i++){
				dis[i]=20000000;
			}
			dis[0]=0;
			dis[1]=0;	
			for(int i=j+1;i<=n;i++){
				minn=100000000;
				mj(island,dis,j,i,d);
				dis[i]=minn;
			}
		}
		cout<<ans<<'\n';
	}	
	return 0;
}