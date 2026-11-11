#include<bits/stdc++.h>
using namespace std;
int a[300000];
int n,m;
long long ans=0;
void dfs(long long zhi,int ii,int im){
	if(im>m){
		ans=max(ans,zhi);
		return;
	}if(n-ii<m-im||ii>n)return ;
	dfs(zhi&a[ii],ii+1,im+1);
	dfs(zhi,ii+1,im);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		dfs(a[i],i+1,2);
	}
	cout<<ans;
	return 0;
} //5 3
//31 3 1 15 7
