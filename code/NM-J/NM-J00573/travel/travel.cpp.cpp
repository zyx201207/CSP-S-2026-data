#include<bits/stdc++.h>
using namespace std;
string rb, ra, ca, cb; 
int main()
{
    freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ra>>rb>>ca>>cb;
	if(ra==ca) cout<<1;
	       else {cout<<"0000";return 0;}
	if(rb[0]==cb[0]&&rb[1]==cb[1]) cout<<1;
	       else {cout<<"000";return 0;}
	if((rb[2]>='A'&&rb[2]<='C')&&(cb[2]>='A'&&cb[2]<='C')) cout<<1;
	                        else if((rb[2]=='F'&&cb[2]=='E')||(rb[2]=='E'&&cb[2]=='F')) {cout<<"11";return 0;}
	                          else {cout<<"00";return 0;}
	if((rb[2]=='A'&&cb[2]=='B')||(rb[2]=='B'&&cb[2]=='C')) cout<<1;
	   else cout<<"0";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
