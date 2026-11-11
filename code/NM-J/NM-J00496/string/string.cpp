#include <bits/stdc++.h>
using namespace std;

long long n;
string s1;
long long ans=0;
string c;

int main(){
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	cin >> n;
	vector<long long> a(n); 
	for(long long i=0;i<n;i++){
		cin >> a[i] >> c[i];
	}
	for(long long i=0,r=n-1;2*i<n;i++,r--){
		if(c[i]!=c[r]){
			ans+=max(a[i],a[r]);
		}
	}
	cout << ans << endl;
}
