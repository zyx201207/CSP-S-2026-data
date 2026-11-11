#include<bits/stdc++.h>
using namespace std;
bool flag1,flag2,flag3,flag4;
long long zw[5]={0,1,2,3,4},k1,k2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string c1,b1,c2,b2;
	cin>>c1>>b1>>c2>>b2;
	if(c1[0]==c2[0]&&c1[1]==c2[1])
	{
		flag1=true;
		if(b1[0]==b2[0]&&b1[1]==b2[1])
		{
			flag2=true;
			if((b1[2]<'D'&&b2[2]<'D')||(b1[2]>='D'&&b2[2]>='D'))
			{
				flag3=true;
				k1=zw[b1[2]-'A'];
				k2=zw[b2[2]-'A'];
				if(abs(k1-k2)==1)
				flag4=true;
			}
		}
	}
	if(flag1==true)
	cout<<'1';
	else 
	cout<<'0';
	if(flag2==true)
	cout<<'1';
	else 
	cout<<'0';
	
	if(flag3==true)
	cout<<'1';
	else 
	cout<<'0';
	
	if(flag4==true)
	cout<<'1';
	else 
	cout<<'0';
	cout<<endl;
	return 0;
}
