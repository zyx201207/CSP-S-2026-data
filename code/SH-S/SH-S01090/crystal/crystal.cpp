#include <bits/stdc++.h> 
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n=0,m=0;
	long long ans=-1;
	cin>>n>>m;
	long long a[n];
	for (long long i=0;i<n;i++){
		cin>>a[i];
	}
	sort (a,a+n);
	for (long long j=0;j<n;j++){
		long long ansn=0,czs=0;
		for (int k=j;k>=0;k--){
			if (a[j]>a[k]){
				ansn+=1;
				czs+=a[j]-a[k];
			}
			if (ansn+1>ans && czs<=m){
				ans=ansn+1;
			}
		}
	}

	cout<<ans;
	return 0;
}
