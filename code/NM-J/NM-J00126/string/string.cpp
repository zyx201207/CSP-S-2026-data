#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s="";
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int j=1;j<=a;j++)s+=c;
	}
	int w=s.size();
	int f=w/2;
	int ans=0;
	for(int i=0;i<f;i++){
		if(s[i]!=s[w-1-i])ans++;
	}
	cout<<ans;
	return 0; 
} 
