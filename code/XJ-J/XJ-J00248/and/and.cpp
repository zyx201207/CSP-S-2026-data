#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	long long ans=-1;
	for(int i=1;i<=n-m+1;i++){
		long long anda=-1;
		for(int j=i;j<i+m;j++){
			anda=(a[j]&anda);
		}
		ans=max(anda,ans);
	}
	cout<<ans;
	return 0;
}
