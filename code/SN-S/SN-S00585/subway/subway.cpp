#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q;
	long long w[10010]={};
	long long k[10010]={};
	long long a[10010]={};
	long long t[10010]={};
	long long x[10010]={};
	long long y[10010]={};
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		cin>>w[i];
	}
	for(long long i=1;i<=n;i++){
		cin>>k[i];
		for(long long j=1;j<=k[i];j++){
			cin>>a[j]>>t[j];
		}
	}
	for(long long i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	cout<<a[1]+t[1]*y[1]<<endl;
	cout<<a[1]+w[1]*y[1]+t[1];
	return 0;
}
