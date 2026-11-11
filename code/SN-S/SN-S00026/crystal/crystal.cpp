#include<bits/stdc++.h>
using namespace std;
long long n,m;
int a[500902],b[500802];
int maxx=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool p=0;
	for(int i=0;i<n;i++)cin>>a[i];
	int o=a[1]-a[0];
	for(int i=0;i<n-1;i++){
		if(a[i+1]-a[i]!=o){
			p=1;
			break;
		}
	}
	if(p==0){
		long long ans=1;
		while(p==0){
			if(ans*(ans+1)*o/2>m){
			//	cout<<" £»";
				cout<<ans;
				return 0;
			}
			ans++;
		}
	}
	sort(a,a+n);
	for(int i=1;i<n;i++){
		b[i]=a[i]-a[i-1]; 
	}
	int ps=1;
	long long cost=0;
	for(int i=1;i<n;i++){
		cost=0;
		ps=1;
		int j=i;
		while(cost<=m&&j<n){
			cost+=ps*b[j++];
			ps++;
		}
		if(cost<=m)ps++;
		if(ps-1>maxx)maxx=ps-1;
		if(maxx>=n-i+1)break;
	}
	cout<<maxx;
	return 0;
}
