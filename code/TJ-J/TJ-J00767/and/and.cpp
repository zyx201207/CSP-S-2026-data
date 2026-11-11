#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans=0;
vector<long long> a(200005);
void dfs(int x,int sum,long long res){
	if(sum==m){
		ans=max(ans,res);
		return;
	}
	if(x>n){
		return;
	}
	if(res==0){
		return;
	}
	for(int i=0;i<=1;i++){
		if(i==0){
			dfs(x+1,sum,res);
		}else{
			dfs(x+1,sum+1,res&a[x]);
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=2000){
		dfs(1,0,2147483647);
		cout<<ans;
	}else{
		sort(a.begin()+1,a.begin()+n+1);
		cout<<a[n-m+1];
	}
	return 0;
}
