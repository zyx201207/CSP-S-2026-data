#include <bits/stdc++.h>
using namespace std;
const int N=1e6+3;
long long n,sum;
long long a[N];
char c[N]; 
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	for(long long i=0;i<n;i++){
		for(long long j=0;j<a[i];j++){
			s+=c[i];
		}
	}
	string t=s;
	long long ans=0;
	reverse(s.begin(),s.end());
	for(long long i=0;i<s.size();i++){
		if(s[i]!=t[i]){
			ans++;
		}
	}
	cout<<ans/2;
	return 0;
} 
