#include<bits/stdc++.h>
using namespace std;
unsigned long long n,m,cnt;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(unsigned long long i=1;i<=n;i++){
		cin>>m>>c;
		for(unsigned long long j=1;j<=m;j++){
			s=s+c;
		}
	}
	unsigned long long len=s.size();
	for(unsigned long long i=0;i<len/2;i++){
		if(s[i]!=s[len-1-i])cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}
