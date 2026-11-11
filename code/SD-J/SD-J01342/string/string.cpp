#include<bits/stdc++.h>
using namespace std;
long long n,a,len,ans;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++)s[j+len]=c;
		len+=a;
	}
	for(int i=1;i<=len/2;i++){
		if(s[i]-'a'!=s[len-i+1]-'a')ans++;
	}
	cout<<ans;
	return 0;
}
