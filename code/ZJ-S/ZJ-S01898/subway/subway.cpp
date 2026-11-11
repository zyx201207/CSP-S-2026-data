#include<bits/stdc++.h>
using namespace std;
int c,n,d,q,k;
long long m,a[500005],t[505],to[5000005],dp[501][501],ans;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<n;i++){
		cin>>t[i];
	}
	for(int i=0;i<n;i++){
		cin>>k;
		for(int i=0;i<k;i++){
			cin>>a[i]>>to[i];
			ans+=to[i];
		}
	}
	cout<<ans<<endl;
	return 0;
}
