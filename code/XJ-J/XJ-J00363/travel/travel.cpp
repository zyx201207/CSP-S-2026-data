#include<bits/stdc++.h>
using namespace std;
long long int a,b,c,d,e,f,pai[10];
string s1,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>a>>s1>>b>>s2;
	//车厢 
	if(a==b)
	  cout<<1;
	else//不在同车厢以下都不成立 
	{
		cout<<"0000";
		return 0;
	}
	//同一排 
	c=(s1[0]-'0')*10+(s1[1]-'0');
	d=(s2[0]-'0')*10+(s2[1]-'0');
	if(c==d)
	  cout<<1;
	else
	{
		cout<<"000";
		return 0;
	}
	//同一排且同侧 
	pai[s1[2]-'A']=1;
	pai[s2[2]-'A']=1;
	e=s1[2]-'A';
	f=s2[2]-'A';
	if((c==d)&&((pai[0]==1&&pai[1]==1)||(pai[0]==1&&pai[2]==1)||(pai[1]==1&&pai[2]==1)||(pai[3]==1&&pai[4]==1)))
	  cout<<1;
	else
	{
		cout<<"00";
		return 0;
	}
	//同一排且同侧且相邻 
	if((c==d)&&((pai[0]==1&&pai[1]==1)||(pai[0]==1&&pai[2]==1)||(pai[1]==1&&pai[2]==1)||(pai[3]==1&&pai[4]==1))&&((e-f==-1||e-f==1)&&(!(e==2&&f==3)||(e==3&&f==2))))
	  cout<<1;
	else
	  cout<<0;
	return 0;
} 
