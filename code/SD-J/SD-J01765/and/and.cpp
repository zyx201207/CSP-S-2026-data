#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200010],max1,f;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		max1=max(max1,a[i]);
		if(i==1){
			f=a[i];
			continue;
		}
		f=f&a[i];
	}
	if(m==1){
		cout<<max1;
		return 0;
	}
	if(m==n){
		cout<<f;
		return 0;
	}
	
	if(m==2){
		int max1=0;
	
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				max1=max(max1,a[i]&a[j]);
			}
		}
		cout<<max1;
		return 0;
	}
	cout<<a[n];
} 


