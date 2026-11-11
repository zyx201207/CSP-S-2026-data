#include<bits/stdc++.h>
using namespace std;
string c,s,cc,ss;
bool f=1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>s>>cc>>ss;
	if(c==cc){
		cout<<1;
	}
	else{
		f=0;
		cout<<0;
	}
	if(s[0]==ss[0]&&s[1]==ss[1]&&f){
		cout<<1;
	}
	else{
		f=0;
		cout<<0;
	}
	if((s[2]<='C'&&ss[2]<='C'||s[2]>='D'&&ss[2]>='D')&&f){
		cout<<1;
	}
	else{
		f=0;
		cout<<0;
	}
	if((!((s[2]=='A'&&ss[2]=='C')||(s[2]=='C'&&ss[2]=='A')))&&f){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}