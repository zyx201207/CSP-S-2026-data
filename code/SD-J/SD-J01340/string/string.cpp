#include<bits/stdc++.h>
using namespace std;
int n;
long long x,len,ans;
char k;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	string s;
	for(int i=1;i<=n;i++){
		cin>>x>>k;
		for(int j=1;j<=x;j++){
			s+=k;len++;
		}
	}
	for(int i=0;i<=len/2-1;i++){
		if(s[i]!=s[len-1-i]) ans++;
	}
	cout<<ans;
	return 0;
}
