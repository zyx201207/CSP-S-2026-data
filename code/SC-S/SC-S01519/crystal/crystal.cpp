#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("crystalin","r",stdin);
	freopen("crystalout","r",stdout);
	cin>>n>>m;
	int i,ans=0;
	int a[i];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]-a[i-1]<=m){
			m=m-a[i]+a[i-1];
			ans++;
		}	
	}
	
	cout<<ans-1;
	return 0;
} 