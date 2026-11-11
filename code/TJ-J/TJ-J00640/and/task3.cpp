#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int ans=0,an=0;
	int n,m;
	cin>>n>>m;
	int a[n+1];
	for(int i=0;i<n;i++){
		cin>>a[i];
	} 
	for(int i=0;i<n;i+=2){
		ans+=a[i]&a[i-1];
	}
	if(n==m){
		cout<<ans;
		return 0;
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		for(int j=i;j<m+i;j++){
			an+=a[i+j]&a[i+j-1];
		}
		ans=max(ans,an); 
	
	}
	cout<<ans;
	return 0;
}
