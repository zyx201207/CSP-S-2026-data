#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,s,d,f;
	cin>>a>>s>>d>>f;
	if(a[0]==d[0]&&a[1]==d[1]) {
		cout<<1;
		if(s[0]==f[0]&&s[1]==f[1]) {
			cout<<1; 
			if((s[2]>='A'&&s[2]<='C'&&f[2]>='A'&&f[2]<='C')||(s[2]>='D'&&s[2]<='E'&&f[2]>='D'&&f[2]<='E')) {
				cout<<1;
				if((s[2]-1==f[2]||s[2]+1==f[2])&&(s[2]!='C'&&f[2]!='D')||(s[2]!='D'&&f[2]!='C')) cout<<1;
				else cout<<0; 
			} 
			else cout<<0<<0;
		}
		else  cout<<0<<0<<0;
	}
	else  cout<<0<<0<<0<<0;
	
	
	
	
	
	
	return 0;
}
