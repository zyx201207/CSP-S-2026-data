#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll m,a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int res=1;
	sort(a+1,a+n+1);
	ll sum=0;
	for(int i=1,j=1;i<=n;i++){
		sum+=a[i];
		while(a[i]*(i-j+1)-sum>m) sum-=a[j],j++;
		res=max(res,i-j+1);
	}
	cout<<res<<"\n";
	return 0;
}