#include<bits/stdc++.h> 
using namespace std;
string xiang1,zuo1,xiang2,zuo2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>xiang1>>zuo1>>xiang2>>zuo2;
	if(xiang1==xiang2)
	{
		cout<<"1";
		if((zuo1[0]==zuo2[0])&&(zuo1[1]==zuo2[1]))
		{
			cout<<"1";
			if(((zuo1[2]<='C')&&(zuo2[2]<='C'))||((zuo1[2]>='D')&&(zuo2[2]>='D')))
			{
				cout<<"1";
				if((zuo1[2]+1==zuo2[2])||(zuo1[2]-1==zuo2[2])) cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		if((zuo1[0]!=zuo2[0])||(zuo1[1]!=zuo2[1])) cout<<"000";
	}
	if(xiang1!=xiang2) cout<<"0000";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
