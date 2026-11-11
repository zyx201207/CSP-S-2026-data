#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;cin>>n;string a=" ";
	long long m=0;
	for(int i=1;i<=n;i++){
		long long x;char y;
		cin>>x>>y;m+=x;
		for(int j=1;j<=x;j++){
			a+=y;
		}
	}long long l=a.size()-1,c=0;
	for(int i=1;i<=l/2;i++){
		if(a[i]!=a[l-i+1])c++;
	}cout<<c<<a;
	return 0;
}
