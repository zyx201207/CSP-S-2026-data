#include<bits/stdc++.h> 
using namespace std;
long long n;
string a;
long long s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		int x;
		char c;
		cin>>x;
		cin>>c;
		for(long long j=1;j<=x;j++) a+=c;
	}
	long long l=a.size();
	for(long long i=0;i<l/2;i++){
		if(a[i]!=a[l-i-1])s++;
	}
	cout<<s;
	return 0;
}
