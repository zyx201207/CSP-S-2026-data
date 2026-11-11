#include<bits/stdc++.h>
using namespace std;
long long a[200005],n,m,ans=0;//n个数，选m个
void dfs(long long cnt1,long long temp,long long id){
	if(cnt1>=m){
		ans=max(temp,ans);
		return;
	}
	cnt1++;
	for(long long i=id+1;i<n-m+cnt1;i++){
		dfs(cnt1,(temp&a[i]),i);
	}
}
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	for(long long z=0;z<n-m+1;z++){
		dfs(1,a[z],z);
	}
	cout<<ans;
	
}
