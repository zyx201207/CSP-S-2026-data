#include<bits/stdc++.h> 
using namespace std;
long long a[300000];
char b[300000];
int main(){
freopen("string.in","r",stdin);	
freopen("string.out","w",stdout);
long long n=0,ans=0,now=0;
cin>>n;
for(int i=1;i<=n;i++){
	cin>>a[i]>>b[i];

}
if(n==1){
	cout<<0;
	return 0; 
}
for(int i=1;i<=n/2;i++){
	if(b[i]!=b[n-i+1]){
		if(a[i]>=a[n-i+1]){
			now=a[i];
		}
		else{
			now=a[n-i+1];
		}
		ans+=now;
		now=0;
		
	}
}
cout<<ans;
	return 0;
}
