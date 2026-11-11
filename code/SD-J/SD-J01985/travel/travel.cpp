#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	char kl=b[b.size()-1],tp=d[d.size()-1];
	b=b.substr(0,b.size()-1);
	d=d.substr(0,d.size()-1);
	if(a==c) cout<<1;
	else{
		cout<<"0000";
		return 0;
	} 
	if(b==d) cout<<1;
	else{
		cout<<"000";
		return 0;
	} 
	if((kl=='D'&&tp=='C')||(kl=='C'&&tp=='D'))cout<<"00";
	else if(abs(int(kl-tp))==1) cout<<"11";
	else if((kl=='A'&&tp=='C')||(kl=='C'&&tp=='A')) cout<<"10";
	else cout<<"00";
	
	return 0;
}
