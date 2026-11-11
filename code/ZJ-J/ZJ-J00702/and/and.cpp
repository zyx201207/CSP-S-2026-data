#include<bits/stdc++.h> 
using namespace std;
int a[200010],n,m,mx;
void d(int x,int s,int ans){
	if(x>=n){
		if(s==m)mx=max(mx,ans);
		return;
	}
	if(n-x-1>=m-s)d(x+1,s,ans);
	if(s<m){
		if(ans==-1)d(x+1,s+1,a[x+1]);
		else d(x+1,s+1,ans&a[x+1]);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	d(0,0,-1);
	cout<<mx;
	return 0;
}
