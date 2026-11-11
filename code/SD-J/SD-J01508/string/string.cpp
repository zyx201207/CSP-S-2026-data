#include <bits/stdc++.h>
using namespace std;
string s;
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	int st=0;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s[st++]=c;
		}
	}
	int l=st-1;
	int ans=0;
	for(int i=0;i<(st-1)/2;i++){
		if(s[i] != s[l-i])ans++;
	}
	cout<<ans;
	return 0;
}
