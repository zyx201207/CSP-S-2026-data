#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,c=0,ans=0;
	scanf("%lld",&n);
	char m;
	long long a[n];
	bool pan=1;
	string b="0";
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]); 
		cin>>m;
		for(int j=1;j<=a[i];j++){
				b+=m;
		}
	}	
	for(int i=1;i<=n;i++){
		c+=a[i];
	}
	for(int i=1;i<=c/2;i++){
		if(b[i]!=b[c-i+1]){
			pan=0;
			ans++; 
		}
	}
	if(pan){
		cout<<0;
		return 0;
	}
	cout<<ans;
		return 0;
} 
