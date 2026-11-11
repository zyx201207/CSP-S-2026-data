#include<bits/stdc++.h>
using namespace std;
char arr[100000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	for(int l=0;l<20015;l++){
		arr[l]='!';
	}
	long long n,c=0,c2=0;
	cin>>n;
	for(long long i=0;i<n;i++){
		long long a;
		cin>>a;
		char b;
		cin>>b;
		for(long long j=0;j<a;j++){
			arr[c]=b;
			c++;
		}
	}
	for(long long i=0;i<c/2;i++){
		if(arr[i]!=arr[c-i-1] and arr[c-i-1]!='!' ){
			arr[i]=arr[c-i-1];
			c2++;
		}
	}
	cout<<c2;
return 0;
}
