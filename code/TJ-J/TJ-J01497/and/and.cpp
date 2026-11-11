#include<bits/stdc++.h>
using namespace std;
int a[200005];
int q[200005];
int ans;
int n,c;
bool check(int x){
	x++;
	while(x%2==0){
		x/=2;
	}
	if(x==1)return 1;
	return 0;
}
void dfs(int idx,int cnt,int sum){
	if(cnt==c){
		ans=max(ans,sum);
	}
	if(idx==n+1){
		return;
	}
	if(cnt==0){
		dfs(idx+1,1,a[idx]);
		dfs(idx+1,0,0);
	}else{
		dfs(idx+1,cnt+1,sum&a[idx]);
		dfs(idx+1,cnt,sum);
	}
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>c;
	bool f1=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(f1&&!check(a[i])){
			f1=0;
		}
	}
	if(f1){
		sort(a+1,a+n+1);
		cout<<a[n-2];
	}else if(n<=28){
		dfs(1,0,0);
	}
	 
	
	cout<<ans;
	return 0;
}
//00001
//00010
//00011
//00100
//00101
//00110
//00111
//01000
//01001
//01010
//01011
//01100
//01101
//01110
//01111
//10000
