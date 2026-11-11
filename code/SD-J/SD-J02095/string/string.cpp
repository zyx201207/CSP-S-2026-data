#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n,ans=0;
	string s="",r="";
	cin>>n;
	for(long long i=0;i<n;i++){
		int k;
		char a;
		cin>>k>>a;
		for(long long j=0;j<k;j++){
			s+=a;
		}
	}
	r=s;
	long long len=s.size();
	for(long long i=0;i<len/2;i++){
		if(r[len-i]!=s[i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
