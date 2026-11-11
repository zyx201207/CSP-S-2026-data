#include<bits/stdc++.h>
using namespace std;
int a[2000009],ans=INT_MAX,sum=0,n,d;
void dfs(int cnt,int start,int end){
	if(cnt>ans){
		return ;
	}
	if(start==end){
		if(ans==cnt){
			sum++;
			return ;
		}
		else if(ans>cnt){
			sum=1;
			ans = cnt;
			return ;
		}
		else{
			return ;
		}
	}
	for(int i = start+1;i<=n;i++){
		if(a[i]-a[start]<=d){
			dfs(cnt+1,i,end);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i = 1;i<=n;i++){
			cin>>a[i];
		}
		int res=0;
		for(int i = 1;i<=n;i++){
			for(int j = i+1;j<=n;j++){
				sum=0,ans=INT_MAX;
				dfs(0,i,j);
				if(sum==2){
					res++;
				}
			}
		}
		cout<<res<<endl;
	}
	return 0;
}
