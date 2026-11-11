#include<bits/stdc++.h>
using namespace std;
int n,m,ans,ma;
int  num[200010];
void dfs(int sum,int cut,int ma1){
	if(ma==0) ma=num[cut];
	else ma=ma and num[cut];
	ma1=ma;
	dfs(sum--,cut++,ma1);
	ma=ma1;
	dfs(sum,cut++,ma1);
	if(sum==0) {
		ans=max(ma,ans);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	dfs(m,0,0);
	cout<<ans;
} 
