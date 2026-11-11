#include<bits/stdc++.h>
using namespace std;

struct tck{
	string tn;
	string sn;
};
int main()
{

	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	
	tck a,b;
	cin>>a.tn>>a.sn;
	cin>>b.tn>>b.sn;
	int sc=1; 
	if(a.tn==b.tn)sc=1;
	else sc=0;
	cout<<sc;
	int pai=1;
	for(int i=0;i<=1;i++)
	{
		if(a.sn[i]!=b.sn[i] || sc==0)pai=0;
	}
	cout<<pai;
	int tc=1;
	if(!pai || (a.sn[2]=='F' && b.sn[2]!='D' )|| (b.sn[2]=='F' && a.sn[2]!='D')||(a.sn[2]=='D' && b.sn[2]!='F' )|| (b.sn[2]=='D' && a.sn[2]!='F'))tc=0;

	cout<<tc;
	if(tc && abs(a.sn[2]-b.sn[2])==1)cout<<1;
	else cout<<0;

	return 0;
}
