#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans=max(a[i],ans);
	}
	if(m==1){
		cout<<ans;
		return 0;
	}
	if(m==2){
	ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ans=max(ans,a[i]&a[j]);
		}
	}
	cout<<ans;
	return 0;}
	sort(a+1,a+n+1);
	cout<<a[n-m+1];
	return 0;	
} 
