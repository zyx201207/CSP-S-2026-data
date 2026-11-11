#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	
	long long n,m,i,s=0;
	cin >> n >> m;
	long long a[n];
	for(i=0;i<n;i++)cin >> a[i];
	sort(a,a+n);
	for(i=0;s+=(a[1]-a[0])*i,m>=s;i++){}
	cout << i;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
