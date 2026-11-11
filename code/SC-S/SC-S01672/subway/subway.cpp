#include<bits/stdc++.h>
using namespace std;
long long w[100005],a[100005],t[100005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		cin>>w[i];
	}
	long long k;
	cin>>k;
	for(int i=1;i<=k;i++){
		cin>>a[i]>>t[i];
	}
	for(int i=1;i<=q;i++){
		long long x,y;
		cin>>x>>y;
		sort(c+1,c+k+1);
       cout<<a[i]+t[i]+y;
	}
	return 0;
}