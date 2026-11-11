#include<bits/stdc++.h>
using namespace std;
const int N=5e5+2;
long long a[N];
int n,m;
bool check(int x){
	for(int fir=0;fir+x<=n;fir++){
		if(((x-1)*a[fir+x]-x*a[fir+x-1]+a[fir])<=m) return true; 
	}
	return false;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) a[i]+=a[i-1];
	int l=1,r=n;
	int mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)) l=mid+1;
		else r=mid-1;
	}
	cout<<r<<endl;
	return 0;
}
