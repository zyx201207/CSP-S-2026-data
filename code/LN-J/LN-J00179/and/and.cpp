#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],ans;
void dfs(int x,int y,int res){
	if(y==m){
		ans=max(ans,res);
		return;
	}
	if(x>n)return;
	dfs(x+1,y+1,(res&a[x]));
	dfs(x+1,y,res);
	return;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,greater<int>());
	if(1 and n<=20)dfs(1,0,INT_MAX);
	else if(m==1)ans=a[1];
	else if(m==n){
		ans=a[1];
		for(int i=1;i<=n;i++)
			ans=ans&a[i];
	}
	else if(n<=2000 and m==2)
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++)
				ans=max(ans,(a[i]&a[j]));
	else{
		int N=n;bool flag=1;
		while(N%2==0)N/=2;
		for(int i=1;i<=n;i++)
			if(a[i]!=n-i){
				flag=0;
				break;
			}
		if(N==1 and flag){
			for(int i=1;i<=n;i<<=1)
				if(m<=i){
					ans=n-i;
					break;
				}
		}
		else{
			ans=a[m];
		}
	}
	cout<<ans;
	return 0;
}
