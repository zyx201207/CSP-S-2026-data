#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long d[n+1];
	memset(d,0,sizeof(d));
	for(int i=1;i<=n;i++){
		d[i]=d[i-1]+(i-1)*(a[i]-a[i-1]);
//		cout<<d[i-1]<<"+"<<i-1<<"*("<<a[i]<<"-"<<a[i-1]<<")="<<d[i]<<endl;
	}
//	for(int i=1;i<=n;i++){
//		cout<<d[i]<<" "<<i<<endl;
//	}
	int ans;
	for(int i=1;i<=n;i++){
		if(d[i]>m){
			break;
		}
		ans=i;
	}
	cout<<ans;
	return 0;
} 