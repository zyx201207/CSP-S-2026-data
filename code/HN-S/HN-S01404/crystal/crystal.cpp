#include<bits/stdc++.h>
using namespace std;
const int N=500005;
long long n,m,a[N],val[N];
bool check(int x){
	for(int i=x;i<=n;i++){
		long long cost=
		val[i]-val[i-x+1]-(a[i]-a[i-x+1])*(i-x);
		if(cost<=m) return true;
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	val[1]=0;
	for(int i=2;i<=n;i++)
		val[i]=val[i-1]+(a[i]-a[i-1])*(i-1);
	int l=1,r=n;
	while(l<r){
		int mid=(l+r+1)/2;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	return printf("%d\n",l),0;
}
