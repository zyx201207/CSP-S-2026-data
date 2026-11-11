#include<bits/stdc++.h>
using namespace std;
int maxx=0; 
int main(){
	freopen("and .in","r",stdin);
	freopen("and .out","w",stdout);
int n,x1,x2,a1,a2,q;
cin>>n;
for(int i=1;i<=n;i++){
	cin>>x1>>x2;
   int e1=x1%2;
   int e2=x2%2;
}
	for(int i=e1;i>=1;e1--) {
		cin>>a1;
	}
	for(int i=e2;i>=1;e2--) {
		cin>>a2;
	}
	int cnt =(a1&&a2);
		
	
	for(int i=0;i<=cnt;i++){
		cin>>q;
		int ans=q[i]*2^i;
	
	ans=max(maxx,ans);
	cout<<ans;
}
	return 0;
}
