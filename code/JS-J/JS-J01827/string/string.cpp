#include <bits/stdc++.h>
using namespace std;

long long n,ans;
string s="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	while (n--){
		long long m;
		string x;
		cin>>m>>x;
		while (m--){
			s+=x;
		}
	}
	long long l=0;
	long long r=s.size()-1;
	while (l<=r){
		if (s[l]!=s[r]) ans++;
		l++;
		r--;
	}
	cout<<ans<<"\n";
	return 0;
}
