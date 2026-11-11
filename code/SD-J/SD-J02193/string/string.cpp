#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	string c;
	long long x=0;
	for(int i=1;i<=n;i++){
		long long a;
		char b;
		cin>>a>>b;
		for(int j=x;j<x+a;j++){
			c[j]=b;
		}
		x=x+a;
	}
	long long l,r;
	if(x%2==0){
		l=x/2-1;
		r=x/2;
	}
	else{
		l=x/2-1;
		r=x/2+1;
	}
	int ans=0;
	for(long long i=0;i<x/2;i++){
		if(c[l-i]!=c[r+i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
