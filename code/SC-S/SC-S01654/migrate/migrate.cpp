#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,a[2000005],sum,n,d;
bool vis[2000005];
pair<int,int> ans;
void dfs(int x,int y,int num){
	if(x==y){
		if(ans.first>num){
			ans={num,1};
		}else if(ans.first==num){
			ans.second++;
		}
		return;
	}
	vis[x]=1;
	int sum=0;
	for(int i=1;i<=y;i++){
		if(a[i]-a[x]<=d && !vis[i]){
			dfs(i,y,num+1);
		}
	}
	vis[x]=0;
}
bool check(int x,int y){
	sum=0;
	ans={0x3f3f3f3f,0};
	memset(vis,0,sizeof(vis));
	dfs(x,y,0);
	return ans.second==2;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);	
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		/*if(c==11 || c==12){
			if(d<a[3]-a[1]) cout<<0;return 0;
			else{
				
			}
		}*/
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(check(i,j)){
					cnt++;
				}
			}
		}
		cout<<cnt<<"\n";
	} 
	return 0;
}//8
