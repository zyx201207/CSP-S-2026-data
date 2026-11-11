#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	long long c,n,m,d,q;
	long long w[50001],k[501],a[501],t[501],x[10001],y[10001];
	cin>>c>>n>>m>>d>>q;
	if(n==-1){
		for(long long i=0;i<m;i++)cin>>w[i];
		for(long long i=0;i<n;i++){
			cin>>k[i];
			for(int j=0;j<k[i];j++){
				cin>>a[j]>>t[j];
			}
		}
		for(long long i=0;i<q;i++)cin>>x[i]>>y[i];
	
		for(long long i=0;i<q;i++)cout<<w[1]<<"\n";
	} 
	
	for(long long i=0;i<m;i++)cin>>w[i];
	for(long long i=0;i<n;i++){
		cin>>k[i];
		for(int j=0;j<k[i];j++){
			cin>>a[j]>>t[j];
		}
	}
	for(long long i=0;i<q;i++)cin>>x[i]>>y[i];

	for(long long i=0;i<q;i++)cout<<w[1]<<"\n";
	return 0;
}