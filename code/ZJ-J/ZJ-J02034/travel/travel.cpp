#include<bits/stdc++.h>
using namespace std;
string c,cl,s,sl;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>cl>>s>>sl;
	if(c==s)cout<<1;
	else cout<<0;
	if(c==s&&cl[0]==sl[0]&&cl[1]==sl[1]){
		cout<<1;
	}else cout<<0;
	int a=cl[2]-'A',b=sl[2]-'A';
	if(c==s&&cl[0]==sl[0]&&cl[1]==sl[1]&&((a<=2&&b<=2)||(a>2&&b>2))){
		cout<<1;
	}else cout<<0;
		if(c==s&&cl[0]==sl[0]&&cl[1]==sl[1]&&((a<=2&&b<=2)||(a>2&&b>2))&&(((a-b)==1)||((b-a)==1))){
		cout<<1;
	}else cout<<0;
	return 0;
}