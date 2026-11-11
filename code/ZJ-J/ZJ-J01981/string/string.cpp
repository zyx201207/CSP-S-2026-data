#include<bits/stdc++.h>
using namespace std;
int l;
string s,h;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>l;
	for(int i=1;i<=l;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int j=1;j<=a;j++)s+=c;
	}
	h=s;
	reverse(s.begin(),s.end());
	if(h==s)cout<<0;
	return 0;
}
