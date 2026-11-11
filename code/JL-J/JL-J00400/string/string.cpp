#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,k,m=1,sum=0;char b;string s;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>k>>b;
		k+=m;
		for(;m<=k;m++){
			s[m]=b;
		}
	}
	for(long long i=1;i<=m/2;i++){
		if(s[i]!=s[m-i]) sum++;
	}
	cout<<sum;
    return 0;	
}
