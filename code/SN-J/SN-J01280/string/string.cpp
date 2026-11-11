#include<bits/stdc++.h>
using namespace std;
long long n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long a[n+5];
	string c;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	if(n==2){
		long long m=min(a[1],a[2]);
		if(c[1]==c[2]){
			cout<<0;
		}
		else{
			cout<<m;
		}
		return 0;
	}
	long long num=1;
	for(int i=1;i<n;i++){
		if(c[i]!=c[i+1]){
			num=0;
			break;
		}
	}
	if(num==1){
		cout<<0;
		return 0;
	}
return 0; 
}
