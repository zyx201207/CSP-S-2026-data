#include<bits./stdc++.h>
using namespace std;
const int N=2e5+5;
long long a[N];
long long m,n;
long long ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n-1);
	for(int i=1;i<=n-1;i++){
		if(m>=i*(a[i+1]-a[i])){
			ans++;
			m=m-i*(a[i+1]-a[i]);
		}
	}
	cout<<ans;
	return 0;
}
