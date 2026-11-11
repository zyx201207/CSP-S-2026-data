#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a[1000005],dp;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+n+1);
	dp=a[n];
    for(int i=n-1;i<=n-m+1;i++){
    	dp=dp&a[i];
	}
	cout<<dp;
	return 0;
}

