#include <bits/stdc++.h>
using namespace std;
string s,ss,t,tt;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s>>ss>>t>>tt;
	int a=(s[0]-'0')*10+s[1]-'0',b=(t[0]-'0')*10+t[1]-'0';
	if(a!=b){
		cout<<0<<0<<0<<0;
		return 0;
	}else
		cout<<1;
	int aa=ss[2]-'A',bb=tt[2]-'A';
	a=(ss[0]-'0')*10+ss[1]-'0',b=(tt[0]-'0')*10+tt[1]-'0';
	if(a==b)
		cout<<1;
	else{
		cout<<0<<0<<0;
		return 0;
	}
	if((aa<=2 && bb<=2) || (aa>=3 && bb>=3)){
		cout<<1;
		if(abs(aa-bb)==1)
			cout<<1;
		else
			cout<<0;
	}else
		cout<<0<<0;
	return 0;
}