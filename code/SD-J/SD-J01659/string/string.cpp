#include<bits/stdc++.h>
using namespace std;
char s[100000010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,t=0,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char ch;
		cin>>x>>ch;
		for(int i=1;i<=x;i++){
			s[++t]=ch;
		}
	}
	for(int i=1;i<=t/2;i++){
		if(s[i]!=s[t-i+1]) ans++;
	}
	cout<<ans;
	return 0;
}
