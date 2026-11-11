#include<bits/stdc++.h>
using namespace std;
int n,m,ans=-1,a[200005];
void f(int u,int v,int w){
	if(u>n){
		if(v==m)ans=max(ans,w);
		return;
	}
	if(v==0)f(u+1,v+1,a[u]);
	else if(v<m)f(u+1,v+1,w&a[u]);
	f(u+1,v,w);
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==1){
		for(int i=1;i<=n;i++)ans=max(ans,a[i]);
		cout<<ans;
		return 0;
	}
	if(m==2){
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++)ans=max(ans,a[i]&a[j]);
		cout<<ans;
		return 0;
	}
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++)ans&=a[i];
		cout<<ans;
		return 0;
	}
	f(1,0,-1);
	cout<<ans;
	return 0;
}
