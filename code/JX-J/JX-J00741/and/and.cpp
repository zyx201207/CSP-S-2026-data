#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],p=0,ans=1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	ans=(a[n-1]&a[n-2]);
	p=n-3;
	for(int i=2;i<m;i++){
		ans=(ans&a[p]);
		p--;
	}
	cout<<ans;  
	return 0;
}
