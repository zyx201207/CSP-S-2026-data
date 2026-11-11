#include<bits/stdc++.h>
using namespace std;
int n,m,a[100003],dp[20003][20003],ans,mx,mi;
int p(int x){
	int y=0;
	while(x>0){
		if(x%2==1)y++;
		x/=2;
	}
	return y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m>>a[1];
	ans=mx=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		ans=ans&a[i];
		if(p(a[i])>p(mx))mx=a[i];
		if(p(a[i])<p(mi))mi=a[i];
	}
	for(int i=1;i<=n;i++)dp[i][1]=a[i];
	if(n==m)cout<<ans;
	else if(m==1)cout<<mx;
	else{
		cout<<mi;
	}
	return 0;
}
