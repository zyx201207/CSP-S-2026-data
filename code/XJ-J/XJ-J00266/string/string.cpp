#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	char a[n+1];
	long long b[n+1],ans=0,max=0;
	for(long long i=1; i<=n; i++) {
		cin>>b[i];
		cin>>a[i];
		max+=b[i];
	}
	string str;
	for(long long i=1;i<=n;i++) {
		for(long long j=1;j<=max;j++){
			str[j]=a[i];
		}
	}
	for(long long i=1,j=str.size();i<=str.size();i++,j--){
		if(str[i]!=str[j]){
			ans++;
		}
	}
	cin>>ans;
}