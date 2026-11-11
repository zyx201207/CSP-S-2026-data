#include<bits/stdc++.h>
using namespace std;
int b[5005][5005][2];
long long c,t,a[2000005],n,d,ans;

void dfs(int x){
	int maxx=0;
	for(int i = x+1 ; i <= n&&a[i]-a[x]<=d;i++){
		b[x][i][0]=1;
		b[x][i][1]=1;
		maxx=max(maxx,i);
	}
	for(int i = 1 ; i < x ;i++){
		for(int j = x+1;j<=maxx;j++){
			if(b[i][j][0]>b[i][x][0]+b[x][j][0]||b[i][j][0]==0){
				ans-=(b[i][j][1]>1);
				b[i][j][1]=max(1,b[i][x][1]*b[x][j][1]);
				b[i][j][0]=b[i][x][0]+b[x][j][0];
				if(b[i][j][1]>1)ans++;
			}else if(b[i][j][0]==b[i][x][0]+b[x][j][0]){
				ans+=(b[i][j][1]==1);
				b[i][j][1]+=1;
			}
		}
	}
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t ;
	while(t--){
		memset(b,0,sizeof(b));
		cin >> n>> d;
		ans=0;
		for(int i = 1; i <= n ; i++)cin >> a[i];
		for(int i = 1 ; i <= n ; i++)dfs(i);
		cout << ans<<endl;
	}
	return 0;
}