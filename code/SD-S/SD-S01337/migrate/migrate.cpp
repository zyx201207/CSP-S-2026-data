#include<bits/stdc++.h>
using namespace std;
long long arr[2000010];
int sum=0,minn=20000000;
long long n,d;
void dfs(int u,int v,int len){
	if(u==v){
		if(len<minn){
			minn=len;
			sum=1;
		}else if(len==minn){
			sum++;
		}
		return;
	}
	for(int i=u+1;i<=n&&arr[i]-arr[u]<=d;i++){
		dfs(i,v,len+1);
	}
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int ans=0;
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>arr[j];
		}
		for(int u=1;u<=n;u++){
			for(int v=u+1;v<=n;v++){
				sum=0,minn=20000000;
				dfs(u,v,0);
				if(sum==2){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
