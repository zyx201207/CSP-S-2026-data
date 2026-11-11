#include<bits/stdc++.h>
using namespace std;
long long n,ans;
string a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		long long x;
		char b;
		cin>>x>>b;
		while(x--){
			a+=b;
		}
	}	
	for(long long i=0;i<a.size()/2;i++){
		if(a[i]!=a[a.size()-i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
