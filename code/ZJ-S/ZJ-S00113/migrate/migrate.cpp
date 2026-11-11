#include<bits/stdc++.h>
#define N 500005
using namespace std;
int c,t,n,d;
int x[2000005];
long long ans;
void dfs(int nw,int ed){
	if(nw==ed){
		ans++;return;
	}
	for(int i=nw+1;i<=ed;i++){
		if(x[i]-x[nw]>d) break;
		dfs(i,ed);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	int cnt;
	while(t--){
		cin>>n>>d;
		ans=0;
		cnt=0;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+2;j<=n;j++){
				ans=0;
				dfs(i,j);
				if(ans==3){
					//cout<<i<<" "<<j<<endl;
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
