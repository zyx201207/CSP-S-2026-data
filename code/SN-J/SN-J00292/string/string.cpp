#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string4.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n=0,sl,ans=0;
	char z;
	string v;
	cin>>n;
	long long x[n];
	for(int i=0;i<n;i++){
		cin>>sl>>z;
		x[i]=sl;
		v+=z;
	}
	for(int i=0;i<v.length();i++){
		if(v[i]!=v[v.length()-i-1]){
			
			ans+=x[i];
		}
	}
	if(ans%2!=0){
		cout<<ans/2+1;
	}else{
		cout<<ans/2;
	}
	
	fclose(stdin);
	fclose(stdout); 
} 
