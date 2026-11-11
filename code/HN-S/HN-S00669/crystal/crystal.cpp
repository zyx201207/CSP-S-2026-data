#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;

#define int long long
int n,m,a[N],t[N];
int rf(int x){
	int l=0,r=n+1,mid;
	while(l+1<r){
		mid=(l+r)/2;
		if(t[mid]-t[x-1]-(a[mid]-a[x-1])*(x-1) <=m) l=mid;
		else r=mid;
	}
	return l;
}


//un
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		int k=a[i]-a[i-1];
		t[i]=t[i-1]+k*(i-1);
	}
	int ma=0;
	for(int i=1;i<=n;i++){
		int r=rf(i);
		ma=max(ma,r-i+1);
	}
	cout<<ma;
	return 0;
}

