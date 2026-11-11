#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],z[N],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		z[i]=a[i]-a[i-1];
		if(z[i]<0) z[i]=-z[i];
	} 
	for(int i=2;i<=n;i++){
		ans+=z[i];
		if(ans>m){
			cout<<i-1;
			return 0;
		}
	}
	cout<<n-1;
	return 0;
}
