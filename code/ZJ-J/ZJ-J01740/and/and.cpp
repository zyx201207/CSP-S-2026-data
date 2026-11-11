#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[200005];
int fun(int x,int y){
	int fs=0,i=0;
	while(x){
		int r1=x%2,r2=y%2;
		if(r2+r1==2){
			fs=fs+pow(2,i);
		}
		x/=2;
		y/=2;
		i++;
	}
	return fs;
}
int ans;
void dfs(int s,int k,int d){
	if(k==0){
		ans=max(ans,s);
		return;
	}
	for(int i=d+1;i<=n;i++){
		if(i==d){
			continue;
		}
//		cout<<s<<" "<<a[i]<<" "<<fun(s,a[i])<<endl;
		dfs(fun(s,a[i]),k-1,i);
	}
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans=max(a[i],ans);
	}
	if(m==1){
		cout<<ans<<endl;
		return 0;
	}else{
		ans=0;
	}
//	cout<<fun(12,15);
	for(int i=1;i<=n;i++){
		dfs(a[i],m-1,i);
	}
	cout<<ans<<endl;
	return 0;
}