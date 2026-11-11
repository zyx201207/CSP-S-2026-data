#include <bits/stdc++.h>
using namespace std;
string s; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int len =0;
	for(int i =1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int j = 0;j<a;j++){
			s[i+len] = c;
		}
		len+=a;
	}
	int ans=0;
	for(int i= 0;i<len/2;i++){
		if(s[i]!=s[len-i-1]) ans++;
	}
	cout<<ans;
	return 0;
}
