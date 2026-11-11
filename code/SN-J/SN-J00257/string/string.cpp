#include<bits/stdc++.h>
using namespace std;
string a;
long long n,c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++){
		long long k;
		char b;
		cin>>k>>b;
		for(int i=0;i<k;i++){
			a+=b;
		}
	}
	for(long long i=0,j=a.length()-1;i<j;i++,j--){
		if(a[i]!=a[j]){
			c++;
		}
	}
	cout<<c;
	return 0;
} 
