#include <bits/stdc++.h>
using namespace std;
	string ca,sa,cb,sb;
	int q,w,e;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ca>>sa>>cb>>sb;
	q=(ca[0]-'0')*10+ca[1]-'0';
	w=(cb[0]-'0')*10+cb[1]-'0';
	if(q==w)
	{
		cout<<1;
		
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	q=(sa[0]-'0')*10+sa[1]-'0';
	w=(sb[0]-'0')*10+sb[1]-'0';
	if(q==w)
	{
		cout<<1;
	}
	else
	{
		cout<<"1000";
		return 0;
	}
	q=sa[2]-'A';
	w=sb[2]-'A';
	if(q==0&&w==1||q==0&&w==2||q==1&&w==0||q==2&&w==0||q==2&&w==1||q==1&&w==0||q==3&&w==4||q==4&&w==3)
	{
		cout<<1;
	}
	else
	{
		cout<<"1100";
		return 0;
	}
	if(abs(q-w)==1)
	{
		cout<<1;
	}
	else
	{
		cout<<"1110";
		return 0;
	}
	return 0;
} 
