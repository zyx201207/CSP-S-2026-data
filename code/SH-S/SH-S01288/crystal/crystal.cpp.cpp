#include<bits/stdc++.h>
using namespace std; 
int n,m,a[500005],b[100005],ans; 
int main(){
	freopen("crystal.in","r",stdin); 
	freopen("crystal.out","w",stdout); 
	cin>>n>>m; 
	for(int i=1; i<=n; i++){
		cin>>a[i]; 
	}
	sort(a,a+n+1); 
	for(int i=2; i<=n; i++){
		a[i]=a[i]-a[i-1]; 
	}
	sort(a,a+n); 
	for(int i=1; i<n; i++){
		if(m>=a[i]) m=m-a[i],ans++; 
		else break; 
	}
	cout<<ans; 
	return 0; 
} 
