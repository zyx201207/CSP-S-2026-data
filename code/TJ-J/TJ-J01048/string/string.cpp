#include<bits/stdc++.h> 
using namespace std;
long long n,ans;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	while(n--){
		long long x;
		string s1;
		cin>>x>>s1;
		for(long long i=1;i<=x;i++){
			s+=s1;
		}
	}
	long long l=0,r=s.size()-1;
	while(l<r){
		if(s[l]!=s[r]) ans++;
		l++;
		r--;
	}
	cout<<ans;
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
