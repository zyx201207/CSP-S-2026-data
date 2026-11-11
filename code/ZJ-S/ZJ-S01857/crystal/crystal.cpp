#include<bits/stdc++.h>
using namespace std;
long long mid,s,n,ans=0,m,l,r,a[500005];
bool check(long long x){
	long long sum=0;
	for(int i=1;i<=x;i++){
		sum+=a[x]-a[i];
	}
	return sum<=m;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	l=1;
	r=n;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
			s=mid;
		}
		else r=mid-1;
	}
	cout<<s;
	return 0;
}