#include<bits/stdc++.h>
using namespace std;
long long a[2000100];
long long m,n;
bool cmp(long long x ,long long y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(long long i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n,cmp);
	long long ans=a[1];
	for(long long i=2;i<=m;i++){
		ans&=a[i];
	}
	cout << ans;
	return 0;
}
