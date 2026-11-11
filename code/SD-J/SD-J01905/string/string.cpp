#include<bits/stdc++.h>
using namespace std;
string s;
long long n,idx=1,cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		long long x;
		char c;
		cin>>x>>c;
		for(long long i=idx;i<idx+x;i++){
			s+=c;
		}
		idx+=x;
	}
	long long l=idx-1;
	for(long long i=0;i<l/2;i++){
		if(s[i]!=s[l+1-i]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
