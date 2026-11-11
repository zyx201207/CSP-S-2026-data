#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ab[500005]={},s[500005],k=1,mx=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)cin>>ab[i];
	sort(ab+1,ab+1+n);
	for (int i=1;i<=n;i++)s[i]=ab[i]+s[i-1];
	for (int i=1;i<=n;i++){
		int sum=ab[i]*(i-k)-(s[i-1]-s[k-1]);
		while(sum>m){
			k++;
			sum=ab[i]*(i-k+1)-(s[i-1]-s[k-1]);
		}
		mx=max(mx,i-k+1);
	}
	cout<<mx;
	return 0;
} 