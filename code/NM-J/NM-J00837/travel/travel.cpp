#include<bits/stdc++.h>
using namespace std;
char a[20];
int main()
{
	int c1,c2,c3,c4,cc1,cc2;
	bool bb,bp,b2,b3;
	//02 01A 02 01B
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    for(int i=1;i<=10;i++){cin>>a[i];}
    cc1=a[5]-'0';
    cc2=a[10]-'0';
	c1=(a[1]-'0')*10+a[2]-'0';
	c3=(a[6]-'0')*10+a[7]-'0';
	c2=(a[3]-'0')*10+a[4]-'0';
	c4=(a[8]-'0')*10+a[9]-'0';
	
	if(c1==c3) {cout<<"1";bb=true;}else cout<<"0";
	if(c2==c4&&bb==true) {cout<<"1";bp=true;}else cout<<"0";
	if(cc1<=19&&cc1>=17&&cc2<=19&&cc2>=17&&bp)b2=true;
	if(cc1<=22&&cc1>=20&&cc2<=22&&cc2>=20&&bp)b3=true;
	if(b2||b3)cout<<"1";else cout<<"0";
	if(cc1==22)cc1=21;
	if(cc2==22)cc2=21;
	if(cc1+1==cc2&&cc1!=19&&bp)cout<<"1";
	else if(cc2+1==cc1&&cc2!=19&&bp)cout<<"1";
	else cout<<"0";
	return 0;
}
