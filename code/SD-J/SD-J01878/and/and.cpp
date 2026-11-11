#include<bits/stdc++.h>
using namespace std;
int const A=2e5+5;
int n,m,ans;
int arr[A];
int dp[A];
bool cmp(int a,int b){
	return a>b;
}
void dfs(int cnt,int rs,int x){
	//if(arr[x]<dp[m]) return ;
	if(x>n||cnt>=m){
		if(cnt==m){
			dp[m]=max(rs,dp[m]);
			//cout<<endl;
		}
		//cout<<endl;
		return;
	}
	//cout<<x<<' '<<arr[x]<<endl;
	dfs(cnt,rs,x+1);
	if(cnt==0){
		//cout<<x<<' '<<arr[x]<<' ';
		dfs(1,arr[x],x+1);
	}
	else{
		if(dp[cnt] > (rs&arr[x])) return;
		dp[cnt]=rs&arr[x];
		//cout<<x<<' '<<arr[x]<<' ';
		dfs(cnt+1,rs&arr[x],x+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%d",&arr[i]);
	}
	sort(arr+1,arr+n+1,cmp);
	dfs(0,0,1);
	printf("%d\n",dp[m]);
	return 0;
}
