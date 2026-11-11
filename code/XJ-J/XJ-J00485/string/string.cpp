#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	string x="";
	cin>>n;
	for(int i=0;i<n;i++){
		long long a;
		char b;
		cin>>a>>b;
		for(int j=0;j<a;j++){
			x+=b;
		}
	}
	string y=x;
	reverse(y.begin(),y.end());
	long long s=0;
	for(long long i=0;i<int(x.size())/2;i++){
		if(x[i]!=y[i])s++;
	}
	cout<<s;
	return 0;
}