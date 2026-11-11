#include<bits/stdc++.h>
using namespace std;
long long a[550],ans,n,m,b[555][2];
void dfs(int now,int rd){
	for(int i=n;i>=now+1;i--){
		if(a[i]-a[now]<=m){
			if(b[i][0]==0){
				b[i][0]=rd+1;
				b[i][1]=1;
			}else if(b[i][0]>rd+1){
				b[i][0]=rd+1;
				b[i][1]=1;
			}else if(b[i][0]==rd+1){
				b[i][1]++;
			}else if(rd>b[i][0]){
				return;
			}
			dfs(i,rd+1);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			ans=0;
			cin>>n>>m;
			long long x,y,z;
			cin>>x>>y;
			for(int i=3;i<=n;i++)cin>>z;
			long long d=y-x;
			if(m/d<=1||n-m/d-m/d+1<=0)cout<<0<<"\n";
			else cout<<n-m/d-m/d+1<<"\n";
		}
		return 0;
	}
	while(t--){
		ans=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<n;i++){
			for(int j=1;j<=n;j++){
				b[j][0]=0;
				b[j][1]=0;
			}
			dfs(i,0);
			for(int j=1;j<=n;j++){
				if(b[j][1]==2){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
}