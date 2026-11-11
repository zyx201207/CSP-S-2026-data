#include <bits/stdc++.h>
using namespace std;

long long n,lenn,ans=0;
string s;

int main(){
	freopen("string.in","r",stdin); 
	freopen("string.out","w",stdout);
	
	
	cin>>n;
	for (int i=0;i<n;i++){
		long long a;
		char c;
		cin>>a>>c;
		lenn+=a;
		for (int i=0;i<a;i++){
			s+=c;
		}
	}
	for (long long i=0;i<s.size()/2;i++){
		if (s[i]!=s[s.size()-i-1]){
			ans++;
		}
	}
	cout<<ans;
}
