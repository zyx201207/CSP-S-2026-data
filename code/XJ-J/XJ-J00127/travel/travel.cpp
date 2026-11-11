#include<bits/stdc++.h>
using namespace std;
string ac,aw,bc,bw;
int main() 
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(0);
	cin>>ac>>aw>>bc>>bw;
	if(ac!=bc)
	{
		cout<<"0000";
		return 0;
	}
	else cout<<"1";
	if(aw[0]!=bw[0]||aw[1]!=bw[1])
	{
		cout<<"000";
		return 0;
	}
	else cout<<"1";
	if(aw[2]=='C'&&bw[2]=='D'||aw[2]=='D'&&bw[2]=='C')
	{
		cout<<"00";
		return 0;
	}
	else cout<<"1";
	if((aw[2]-bw[2]+0)!=-1&&(aw[2]-bw[2]+0)!=1)
	{
		cout<<"0";
	}
	else cout<<"1";
	return 0;
}
