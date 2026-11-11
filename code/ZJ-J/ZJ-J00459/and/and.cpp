#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n,m;
int a[200005];
ll dfs(int k,int sum,int j){
	if(k==m)return sum;
	ll mx=0;
	for(int i=j+1;i<=n;i++){
		mx=max(mx,dfs(k+1,sum&a[i],i));
	}
	return mx;
}
int main(){
ios::sync_with_stdio(0);
cin.tie(0);cout.tie(0);
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++)cin>>a[i];
ll mx=0;
for(int i=1;i+m<=n;i++){
	mx=max(mx,dfs(1,a[i],i));
}
cout<<mx;
return 0;
}
