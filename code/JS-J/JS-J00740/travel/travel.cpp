#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s,ss,c,cc;
	cin>>c>>s>>cc>>ss;
	if(c[0]!=cc[0]||c[1]!=cc[1]){
		cout<<"0000";
		return 0;
	}else{
		cout<<1;
		if(s[0]!=ss[0]||s[1]!=ss[1]){
			cout<<"000";
			return 0;
		}
		else{
			cout<<1;
			if((ss[2]>='D'&&s[2]<='C')||(ss[2]<='C'&&s[2]>='D')){
				cout<<"00";
				return 0;
			}
			else {
				cout<<1;
				if((ss[2]=='A'&&s[2]=='C')||(ss[2]=='C'&&s[2]=='A'))cout<<'0';
				else cout<<1;
			}
		}
	}
	return 0;
}
