#include <bits/stdc++.h>
using namespace std;
int n,a,si,ans;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		getchar();
		cin>>c;
		for(int i=1;i<=a;i++) s[si]=c,si++;
	}
	for(int i=0;i*i<si;i++){
		if(s[i]!=s[si-i]) ans++;
	}
	cout<<ans;
	return 0;
}
//-O2 -std=c++14 -static
//-O2 -std=c++14 -static
//string
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b




*/
