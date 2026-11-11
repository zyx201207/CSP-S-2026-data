#include<bits/stdc++.h>
using namespace std;
long long a, b;
int n, x;
char y;
string s;
int main()
{
	reopen("string.in","r","stdin");
	reopen("string.out","w","stdout");
	cin>>n;
	for(int i=1; i<=n; i++){
		a=a+x;
		cin>>x>>y;
		for(int j=1; j<=x; j++){
			s=s+y;
		}
	}
	for(int i=0; i<n; i++){
		if(s[i]!=s[a-i]){
			s[i]=s[a-i];
			b++;
		}
	}
	cout<<b;
	return 0;
}