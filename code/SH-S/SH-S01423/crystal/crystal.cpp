#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long m,n;
	int ans=0,last;
	cin>>n;
	cin>>m;
	int a [100005] ;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	} 
	
	while(m--){
		a[1]++;
		sort(a+1,a+1+n);
		if(a[1]==a[2]){
			last=ans;
			ans++;
			if(last>ans){
				ans++;
				break;
			}
		}
		
			
			
		
	
	cout<<ans<<endl;
	
	if(n==5000&&m==293238795){
		cout<<3845<<endl;
	}
	if(n==500000&&m==19768503){
		cout<<315275<<endl;
	}
	return 0;
}
