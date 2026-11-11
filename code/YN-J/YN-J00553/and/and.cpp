#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
int n,m,a[N];
long long b[40];
long long ans;
void dfs(int now,int k,long long sum){
	if(k==m){
		ans=max(ans,sum);
		return;
	}
	if(now>n)return;
	dfs(now+1,k+1,sum&a[now]);
	dfs(now+1,k,sum);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	long long x=1;
	for(int i=2;i<=31;i++)x=x*2,b[i]=x-1;
	bool flag=0,ok=0;
	for(int i=1;i<=n;i++){
		flag=0;
		for(int j=1;j<=31;j++){
			if(a[i]==b[j]){
				flag=1;
				break;
			}
		}
		if(flag==0){
			ok=1;
			break;
		}
	}
	if(ok==0){
		sort(a+1,a+n+1);
		ans=a[n];
		for(int i=n-1;i>n-m;i--)ans=ans&a[i];
		cout<<ans;
		return 0;
	}
	dfs(1,0,x-1);
	cout<<ans;
	return 0;
}
