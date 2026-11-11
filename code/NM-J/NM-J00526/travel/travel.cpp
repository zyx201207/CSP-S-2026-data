#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);					
	freopen("travel.out","w",stdout);
	string ar,br,ax,bx;
	cin>>ar>>ax>>br>>bx;
	if(ar==br) cout<<"1";
	        else {cout<<"0"<<"0"<<"0"<<"0";return 0;}
	if((ax[0]==bx[0])&&(ax[1]==bx[1])) cout<<"1";
	                            else {cout<<"0"<<"0"<<"0";return 0;}
	if(((ax[2]=='A')&&(bx[2]=='B'))||((ax[2]=='B')&&(bx[2]=='A'))||((ax[2]=='C')&&(bx[2]=='A'))||((ax[2]=='A')&&(bx[2]=='C'))||((ax[2]=='C')&&(bx[2]=='B'))||((ax[2]=='B')&&(bx[2]=='C'))||((ax[2]=='F')&&(bx[2]=='D'))||((ax[2]=='D')&&(bx[2]=='F')))cout<<"1";
	                                                                                                                                                                                 else {cout<<"0"<<"0";return 0;}
	if(((ax[2]=='A')&&(bx[2]=='B'))||((ax[2]=='B')&&(bx[2]=='A'))||((ax[2]=='C')&&(bx[2]=='B'))||((ax[2]=='B')&&(bx[2]=='C'))||((ax[2]=='F')&&(bx[2]=='D'))||((ax[2]=='D')&&(bx[2]=='F'))) cout<<"1";
	                                                                                                                                                                                else {cout<<"0";return 0;}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
