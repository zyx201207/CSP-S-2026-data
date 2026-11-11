#include <bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
char a,b;
int cnt1=0,cnt2=0,cnt3=0,cnt4=0;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	cnt1=(s1[0]-'0')*10+(s1[1]-'0');
	cnt2=(s3[0]-'0')*10+(s3[1]-'0');
	if(cnt1==cnt2) cout<<1;
	else 
	{
		cout<<"0000";
		return 0;
	}
	cnt3=(s2[0]-'0')*10+(s2[1]-'0');
	cnt4=(s4[0]-'0')*10+(s4[1]-'0');
	if(cnt3==cnt4) cout<<1;
	else 
	{
		cout<<"000";
		return 0;
	}
	a=s2[2],b=s4[2];
	if(a>b) swap(a,b);
	if(b<='C')
	{
		cout<<1;
		if(b-a==1) cout<<1;
		else cout<<0;
	}
	else if(a>='D')
	{
		cout<<11;
	}
	else
	{
		cout<<"00";
	}
	return 0;
}