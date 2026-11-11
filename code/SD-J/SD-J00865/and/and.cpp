#include<bits/stdc++.h>
using namespace std;
long long n,m,MAX=INT_MIN,a[200009],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(m==1){
		cout<<a[n];
		return 0;
	} 
	ans=a[n]&a[n-1];
	for(int i=n-2;i>=n-m+1;i--){
		ans=ans&a[i];
	}
	cout<<ans;
	return 0;
} 
