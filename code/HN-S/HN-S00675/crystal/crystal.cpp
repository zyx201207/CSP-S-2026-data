#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e5+5;
int n,m;
int a[N];
int pre[N];
bool check(int l,int r){
	return (a[r]*(r-l+1)-(pre[r]-pre[l-1]))<=m;
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
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=0,r=n-i+1,p;
		while(l<=r){
			int mid=l+(r-l)/2;
			if(check(i,i+mid-1)){
				l=mid+1;
				p=mid;
			}else{
				r=mid-1;
			}
		}
		ans=max(ans,p);
	}
	cout<<ans;
	return 0;
}
/*

5 8
-3 -1 2 2 7

5 5
1 2 4 8 9

*/
