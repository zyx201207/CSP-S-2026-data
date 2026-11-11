#include<bits/stdc++.h>
using namespace std;
int c,t,a[2000002],vis[2000002],ans,num[2000002],n,d;
bool k;
void dfs(int s,int e,int step){
	if(s==e){
		num[step]++;
	}
	for(int i=0;i<n;i++){
		if(vis[i]==0&&abs(a[i]-a[s])<=d){
			vis[i]=1;
			dfs(i,e,step+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=0;i<t;i++){
		cin>>n>>d;
		for(int j=0;j<n;j++)cin>>a[j];
		if(c<=6){
			for(int j=0;j<n;j++){
				for(int u=j;u<n;u++){
					dfs(j,u,0);
					for(int k=0;k<=2000002;k++){
						if(num[k]!=0){
							if(num[k]==2)ans++;
							break;
						}
					}
					memset(vis,2000002,0);
					memset(num,2000002,0);
				}
			}
			cout<<ans<<endl;
		}else cout<<0<<endl;
	}
}

