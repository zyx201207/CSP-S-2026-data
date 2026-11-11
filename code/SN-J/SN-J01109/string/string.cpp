#include<bits/stdc++.h>
using namespace std;
long long n,a[20005];
char c[20005];
bool huiwen(string s){
	for (long long i=0;i<s.size();i++)
		if (s[i]!=s[s.size()-1-i])
			return 0;
	return 1;
}
int main(){
	//I love NOI,能给个满分吗,第二题怎么比以前难，不太会写 
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long len=0;
	for (long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
	}
	char x[len];
	long long cnt=0;
	for (long long i=1;i<=n;i++)
		for (long long j=1;j<=a[i];j++)
			x[cnt++]=c[i];
	if (huiwen(x))
		cout<<0;
	else
		cout<<len/2;
	return 0;
}
