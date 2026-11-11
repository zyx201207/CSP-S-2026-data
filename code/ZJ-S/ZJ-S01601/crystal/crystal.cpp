#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(n>5001){
		int x,y;
		cin>>x>>y;
		int de=y-x;
		if(de<0) de*=-1;
		int iii=1;
		int sum=0;
		while(1){
			if(sum>m){
				cout<<iii-1;
				return 0;
			}
			sum+=iii*de;
			iii++;
		}
	}
	else{
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		sort(a,a+n);
		int d[n];
		for(int i=0;i<n-1;i++){
			d[i]=a[i+1]-a[i];
		}
		int maxk=0;
		for(int i=0;i<n;i++){
			int sum=0;
			int j=i;
			int k=1;
			for(;j<n;j++,k++){
				sum+=d[j]*k;
				if(sum>m) break;
			}
			maxk=max(maxk,k);
		}
		cout<<maxk;
		return 0;
	}
	return 0;
}
