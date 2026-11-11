#include <bits/stdc++.h>
using namespace std;
void Seagu1l(){
	int n,m;
	cin>>n>>m;
	int a[n+1];
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	bool flag1=true;
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=a[2]-a[1]){
			flag=false;
			break;
		}
	}
	if(flag1){
		if(a[2]-a[1]>=2*b){
			cout<<0;
			return ;
		}
		
	}
	vector<int> ma[n+1];
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			if(a[i]-a[j]<=m){
				ma[j].pushback(i);
			}
		}
	}
	queue<int> q;
	int dp[n+1][n+1];
	
	for(int i=1;i<=n-3;i++){
		for(int j=i+3;j<=n;j++){
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		Seagu1l();
	}
	return 0;
}
