#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	string s="";
	for(int i=1;i<=n;i++){
		long long x;
		char c;
		cin>>x>>c;
		for(long long j=1;j<=x;j++){
			s+=c;
		}
	}
	long long len=s.size();
	long long cnt=0;
	for(long long i=0;i<len;i++){
		if(s[i]!=s[len-1-i]){
			cnt++;
		}
	} //fkw
	cout<<cnt/2;
	return 0;
} 
