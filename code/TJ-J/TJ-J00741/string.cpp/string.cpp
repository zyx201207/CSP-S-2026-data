#include <bits/stdc++.h>
using namespace std;
string s,s1,s2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long cnt=0;
	int n;
	cin>>n;
	for(long long i=1;i<=n;i++){
	char wh;long long cc;cin>>cc>>wh;
	for(long long j=1;j<=cc;j++){
	s+=wh;
}
}
for(int i=0;i<s.size()/2;i++)
if(s[i]!=s[s.size()-i-1])cnt++;

cout<<cnt;
	return 0;
} 
