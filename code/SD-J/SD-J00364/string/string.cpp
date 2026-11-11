#include<bits/stdc++.h>
using namespace std;
long long n,l;
string s;
string s1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(long long i = 0;i<n;i++){
		long long a;
		char c; 
		cin>>a>>c;
		for(long long j = 0;j<a;j++){
			s1 += c;
		}
		s+=s1;
		s1 = "";
	} 
	long long l = s.size();
	long long ans = 0;
	long long mid = l/2+1;
	if(l % 2 != 0){
		for(long long i = 0;i<mid;i++){
		if(s[i] != s[l-i-1]){
			ans++;
		}
	}
	}else{
		for(long long i = 0;i<mid;i++){
		if(s[i] != s[l-i]){
			ans++;
		}
	}
	}
	cout<<ans;
}
