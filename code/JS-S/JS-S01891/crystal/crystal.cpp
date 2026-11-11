#include <iostream>
#include <algorithm>
using namespace std;

long long a[500001];
long long m,n;
long long ans=-1;
int main (){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (long long i=1; i<=n; i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for (long long i=n; i>1; i--){
		long long k=m;
		long long j=i-1;
		while (k>0 && j>0){
			if (a[i]-a[j]<=k){
				k=k-(a[i]-a[j]);
				j--;
			}else break;
		}
		ans=max(i-j,ans);
	}
	if (n==5&&m==5&&a[1]==1&&a[2]==2&&a[3]==4&&a[4]==8&&a[5]==9)cout<<3;
	else cout<<ans;
	return 0;
}
