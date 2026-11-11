#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.ans","w",stdout);
	
	int n;
	cin>>n;
	char s[100000];
	int len=0;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s[len]=c;
			len++;
		}
	}
	int ans=0;
	int l=0,r=len;
	for(;l<r;l++,r--){
		if(s[l]!=s[r]) ans++;
	}
	cout<<ans;
	return 0;
}