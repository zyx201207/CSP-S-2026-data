#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],s[500005];
bool check(int num){
	for(int i=num;i<=n;i++){
		if(num*a[i]-(s[i]-s[i-num])<=m) return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	int l=1,r=n;
	while(l<r){
		int mid=(l+r+1)/2;
		if(check(mid)){
			l=mid;
		}else{
			r=mid-1;
		}
	}
	cout<<l;
	return 0;
}
