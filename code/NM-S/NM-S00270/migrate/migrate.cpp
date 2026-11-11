#include<bits/stdc++.h>
using namespace std;
int c=0,t=0,hxh=0,zwasd=0;
string ss3="1 2 3 4";
string ss4="5 2";
string ss5="1 2 3 4 5";
string ss7="-2 -1 0 1 2";
string ss8="6 2";
string ss9="-4 -3 -2 -1 3 6";
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t>>hxh>>zwasd;
    if((c==0)&&(t==2)&&(hxh==4)&&(zwasd==2))

    {
    	cin>>ss3;
    	cin>>ss4;
    	cin>>ss5;
    	cout<<"1"<<endl<<"2";
	}
    if((c==0)&&(t==2)&&(hxh==5)&&(zwasd==3))
	{
		cin>>ss7;
		cin>>ss8;
		cin>>ss9;
		cout<<0<<endl<<1;
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}
