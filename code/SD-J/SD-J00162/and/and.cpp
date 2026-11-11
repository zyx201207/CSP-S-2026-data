#include<bits/stdc++.h>
using namespace std;
int ans=0;
int a[200005];
int n,m;
void dfs(int cnt,long long sum,int pos){
	if(cnt>m){
		if(sum>ans){
			ans=sum;
		}
		return ;
	}
	for(int i=pos;i<=n;i++){
		dfs(cnt+1,sum&a[i],i+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long s=(1<<31)-1;
	dfs(1,s,1);
	cout<<ans;
	return 0;
}
