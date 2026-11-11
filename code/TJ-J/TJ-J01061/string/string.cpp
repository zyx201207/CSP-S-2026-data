#include <bits/stdc++.h>
#include <string>
using namespace std;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	string q;
	int n;
	cin>>n;
	int shu;
	int jishu=0;
	int jishu2=0;
	for(int i=0;i<n;i++){
		cin>>shu;
		cin>>q[i];
		for(int l=jishu;l<jishu2+shu;l++){
			s[jishu]=q[i];
			
		}
		jishu2+=shu;
		jishu+=shu;
	}
	
	for(int i=0;i<jishu;i++){
		cout<<s[i];
	}
	
	int l=s.size()-1;
	int z=0;
	
	for(int i=0; i<s.size(); i++) {

		if(s[i]!=s[l]) {
			z++;

		}
		if(i==l) {
			break;
		}
		l--;

	}

	cout<<z;
	return 0;
}


