#include<bits/stdc++.h>
using namespace std;
int a[2000010];
int n,d,ans=100000,aa;
bool vis[2000010];
void dfs(int x,int j,int cnt){
	if(x==j){
		if(cnt<ans){
			ans=cnt;
			aa=0;
		}
		else if(cnt==ans){
			aa+=1;
		}
	}
	for(int i=1;i<=n;i++){
		if(i==x||abs(a[x]-a[i])>d||vis[i])continue;
		vis[x]=true;
		dfs(i,j,cnt+1);
		vis[x]=false;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int sum=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				ans=0x3f;aa=0;
				dfs(i,j,0);
				if(aa==1){
					sum++;
				} 
			}
		}
		cout<<sum<<endl;
	}
	return 0;
} 
