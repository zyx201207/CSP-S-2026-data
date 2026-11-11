#include<bits/stdc++.h>
using namespace std;
long long n,num=0,ans=0;
string c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long a[n];
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		num+=a[i];
	}
	if(num/2!=0){
		ans=num/2;
		for(int i=1;i<=n/2;i++){
			if(c[i]=='a'){
				ans--;
			}
		}
		cout<<ans;
	}
	if(num/2==0){
		for(int i=1;i<=n;i++){
			if(c[i]!='a'){
				ans+=a[i];
			}
		}
		cout<<ans;
	}
	for(int i=0;i<n;i++){
		if(c[i]==c[n-i]){
			cout<<'0';
		}
	}
	return 0;
} 
