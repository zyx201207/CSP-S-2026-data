#include<bits/stdc++.h>
using namespace std;
string a="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin >> n;
	for(long long i=1;i<=n;i++){
		long long x;
		string s;
		cin >> x >> s;
		for(long long j=1;j<=x;j++){
			a+=s;
		}
	}
	long long o=a.size()-1,ans=0;
	for(long long i=0;i<o/2;i++){
		if(a[i]!=a[o-i]){
			ans++;
		}
	}
	cout << ans;
	return 0;
}
