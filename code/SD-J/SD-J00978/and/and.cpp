#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+5;
long long n,m,a[N];
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	long long ans=a[1];
	for(long long i=1;i<m;i++){
		ans=ans&a[i+1];
	}
	cout<<ans;
	return 0;
}
