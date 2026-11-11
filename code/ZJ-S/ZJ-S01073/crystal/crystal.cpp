#include<bits/stdc++.h>
using namespace std;
#define int long long
int pre[500010];
int a[500010];
int n,m;
bool check(int x){
	for(int i=x;i<=n;i++){
		if(a[i]*(x-1)-(pre[i-1]-pre[i-x])<=m){
			return 1;
		}
	}	
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	int l=1,r=n;
	while(l<r){
		int mid=(l-r)/2+r;
		if(check(mid)){
			l=mid;
		}
		else{
			r=mid-1;
		}
	}
	cout<<l;
	return 0;
}





