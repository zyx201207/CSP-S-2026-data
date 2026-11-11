#include<bits/stdc++.h>
using namespace std;
long long n,a[5000001],m;
bool ch(long long p){
	long long an=0,q=0;
	for(int i=1;i<=p;i++){
		an+=a[p]-a[i];
		if(an>m) return 0;
	}
	q=an;
	for(int i=0;i+p<n;i++){
		an-=a[i+p]-a[i];
		q=min(q,an);
	}
	if(m>=an) return 1;
	return 0;
}
long long rf(){
	long long l=0,r=m,mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(ch(mid)) l=mid+1;
		else r=mid-1;
	}
	return r;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	cout<<rf();
	return 0;
}
