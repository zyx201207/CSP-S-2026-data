#include<bits/stdc++.h>
using namespace std;
int aa,ba,ab,bb;char za,zb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char x;
	cin>>x;
	aa+=(x-'0');
	cin>>x;
	aa=aa*10+(x-'0');
	cin>>x;
	ba+=(x-'0');
	cin>>x;
	ba=ba*10+(x-'0');
	cin>>za;
	if(za=='F')za='E'; 
	cin>>x;
	ab+=(x-'0');
	cin>>x;
	ab=ab*10+(x-'0');
	cin>>x;
	bb+=(x-'0');
	cin>>x;
	bb=bb*10+(x-'0');
	cin>>zb;
	if(zb=='F')zb='E';
	if(aa==ab)cout<<1;
	else{
		cout<<"0000";return 0;
	}
	if(ba==bb)cout<<1;
	else{
		cout<<"000";return 0;
	}
	if((za<='C'&&zb<='C')||(za>='D'&&zb>='D'))cout<<1;
	else{
		cout<<"00";return 0;
	}
	if(abs(int(za-zb))==1)cout<<1;
	else cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
