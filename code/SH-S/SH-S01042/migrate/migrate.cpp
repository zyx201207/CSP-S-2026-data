#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t,n,d,a[500005];
bool check(int x,int y){
	return a[y]-a[x]<=d;
}
int f(int l,int r){
	while(l+1<=r){
		int mid=(l+r)/2;
		if(check(l,mid)) l=mid;
		else r=mid;
	}
	return l;
}
void dfs(int nx){
	if(nx==n) return ;
	int nxt=f(nx,n);
	if(nxt==nx) return ;
	for(int i=nx;i<=nxt;i++){
		dfs(i);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<+n;i++){
			cin>>a[i];
		}
		int mx=0,step=0;
		int nxt=f(2,n);
		for(int i=2;i<=nxt;i++){
			dfs(i);
			step++;
		}
//		for(int i=1;i<n;i++){
//			if(i+1==n){
//				step++;
//				
//			}
//			int nxt=f(i+1,n);
//		}
		cout<<step;
	}
	return 0;
} 
