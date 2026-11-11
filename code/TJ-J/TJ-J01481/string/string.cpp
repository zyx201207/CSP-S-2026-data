#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,x,k=0;
	char y;
	string s[10000];
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>x>>y;
		while(x--){
			s[k]=y;
			k++;
		}
	}
	long long ans=0;
	for(long long i=0;i<=k/2;i++){
		if(s[i]!=s[k-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
