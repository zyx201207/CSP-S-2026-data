#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	long long sum=0,l=1;
	for(int i=1;i<=n;i++){
		sum+=(i-l)*(a[i]-a[i-1]);
		while(sum>m){
			sum-=(a[i]-a[l]);
			l++;
		}
		ans=max(ans,i-l+1);
	}
	cout << ans << endl;
}