#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005];
long long dfs(int x,int c){
	if(c==m) return a[x-1];
	if(x>n) return 0;
	return max(a[x]&dfs(x+1,c+1),dfs(x+1,c));
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(m==2){
		long long u=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			for(int j=1;j<i;j++){
				u=max(u,1ll*a[i]&a[j]);
			}
		}
		cout<<u;
	}else if(m==1){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+1+n);
		cout<<a[n];
	}else if(m==n){
		cin>>a[1];
		long long u=a[1];
		for(int i=2;i<=n;i++){
			cin>>a[i];
			u&=a[i];
		}
		cout<<u;
	}else if(n<=20){
		for(int i=1;i<=n;i++) cin>>a[i];
		cout<<dfs(1,0);
	}else{
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+1+n);
		cout<<a[n-m+1];
	}
	return 0;
}
