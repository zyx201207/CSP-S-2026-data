#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+5;
long long n,m,a[N],cnt;
unsigned long long ans=0;
int main(){//再见，c++，在下个世界线再会 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;;i++){
		ans+=(i-1)*(a[i]-a[i-1]);
		if(ans>m) break;
		cnt=i;
	}
	cout<<cnt;
	return 0;
}
