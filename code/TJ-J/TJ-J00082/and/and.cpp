#include<bits/stdc++.h>
using namespace std;
const int N=2*100000;
long long n,m,ans,x1,x2;
long long a[N+5];
void dfs(int id,long long sum,int k){
	if(k==m){
		ans=max(ans,sum);
		return ;
	}
	for(int i=id;i<=n;i++){
		dfs(i+1,a[i]&sum,k+1);
		sum=a[i];
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		x1=max(x1,a[i]);
		if(i==1){
			x2=a[i];
		}
		else{
			x2=x2&a[i];
		}
	}
	if(m==1){
		cout<<x1;
		return 0;
	}
	else if(m==n){
		cout<<x2;
		return 0;
	}
	dfs(1,a[1],1);
	cout<<ans;
	return 0;
}


