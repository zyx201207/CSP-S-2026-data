#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int j=1;j<=a;j++) s+=c;
	}
	int x=s.size();
	for(int i=0;i<=x/2;i++){
		if(s[i]!=s[x-1-i]) ans++;
	}
	cout<<ans;
	return 0;
 } 
