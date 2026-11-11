#include<bits/stdc++.h>
using namespace std;
#define int long long
string a,b,sa,sb;
char ca,cb;
int numa,numb;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>sa>>b>>sb;
	if(a!=b){
		cout<<"0000";
		return 0;
	}
	numa=(sa[0]-'0')*10+sa[1]-'0';
	numb=(sb[0]-'0')*10+sb[1]-'0';
	ca=sa[2];
	cb=sb[2];
	if(numa!=numb){
		cout<<"1000";
		return 0;
	}
	if(ca>cb)swap(ca,cb);
	if(!((ca<='C'&&cb<='C')||(ca>'C'&&cb>'C'))){
		cout<<"1100";
		return 0;
	}
	if((cb-ca==1&&ca!='C')||(ca=='D'&&cb=='F'))cout<<"1111";
	else cout<<"1110";
	return 0;
}
