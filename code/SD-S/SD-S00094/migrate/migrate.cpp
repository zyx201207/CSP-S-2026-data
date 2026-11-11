#include <bits/stdc++.h>
using namespace std;
long long c,t,n,d;
long long sum;
long long a[2000010];
long long dis[2000010];
void dfs(int x1,int y1,int fei){
	if(x1==y1){
		sum++;
		dis[sum]=fei;
		return;
	}
	for(int i=x1+1;i<=y1;i++){
		if(a[i]-a[x1]<=d){
			dfs(i,y1,fei+1);
		}
		else return;
	}
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int cnt=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				sum=0;
				dfs(i,j,0);
				sort(dis+1,dis+sum+1);
				if(sum>=2&&dis[1]==dis[2]&&dis[2]!=dis[3]) cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
