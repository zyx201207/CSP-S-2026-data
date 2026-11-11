#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N],s[N];
bool check(int x){
	int sum=1e18;
	for(int i=x;i<=n;i++){
		sum=min(sum,a[i]*(x-1)-(s[i-1]-s[i-x]));
	}
	return sum<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	int l=0,r=n;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(check(mid)){
			l=mid;
		}else{
			r=mid-1;
		}
	}
	cout<<r;
	return 0;
}
//Oct31==Dec25?
