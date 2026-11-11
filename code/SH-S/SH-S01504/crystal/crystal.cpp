#include <bits/stdc++.h>
using namespace std;
long long a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ans=0,f=0;
	cin >> n >> m;
	for(long long i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a,a+n);
	long long sum=0,l=0;
	for(long long i=0;i<n;i++){
		f+=(i-l)*(a[i]-a[i-1]);
		while(f>m){
			f-=(a[i]-a[l]);
			l++;
		}
		ans=max(ans,i-l+1);
		sum+=a[i];
	}
	cout << ans << endl;
	return 0;
}
