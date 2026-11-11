#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		long long t;
		char a;
		cin>>t>>a;
		for(long long j=1;j<=t;j++){
			s+=a;
		}
	}
	long long cnt=0;
	for(long long i=0;i<s.size();i++){
		if(s[i]!=s[s.size()-1-i]){
			cnt++;
		}
		if(i==s.size()-1-i){
			break;
		}
	}
	cout<<cnt;
	return 0;
}
