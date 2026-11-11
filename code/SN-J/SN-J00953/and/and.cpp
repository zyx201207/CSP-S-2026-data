#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],ans,j;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	j=n-2;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ans=(a[n]&a[n-1]);
	for(long long i=0;i<m-2;i++){
		ans=(ans&a[j]);
		j--;
	}
	cout<<ans;
	return 0;
}
