#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int cx=0,pai=0,tc=0,lin=0;
struct seat{
	int num,pos;//对应排和列 
}R,X;
//pos: A-1 B-2 C-3 D-4 (E-5) F-6
bool check2()
{
	if(R.num==X.num)return true;
	return false;
}
bool check3()
{
	if(check2())
	{
		if((R.pos==6&&X.pos==4)||(R.pos==4&&X.pos==6))
		{
			return true;
		}
		else if((R.pos>=1&&R.pos<=3)&&(X.pos>=1&&X.pos<=3))
		{
			return true;
		}
	}
	return false;
}
bool check4()
{
	if(abs(R.pos-X.pos)==1)
	{
		return true;
	}
	else if((R.pos==6&&X.pos==4)||(R.pos==4&&X.pos==6))
	{
		return true;
	}
	return false;
} 
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cx=1;//situation 1
	else {
		cout<<"0000\n";
		return 0;
	}
	
	for(int i=0;i<(int)s1.size();i++)
	{
		if(s1[i]>='0'&&s1[i]<='9')
		{
			R.num*=10;
			R.num+=(int)(s1[i]-'0');
	 	}
	 	else if(s1[i]>='A'&&s1[i]<='F')
	 	{
	 		R.pos=(int)(s1[i]-'A')+1;
 		}
	}
	
	for(int i=0;i<(int)s2.size();i++)
	{
		if(s2[i]>='0'&&s2[i]<='9')
		{
			X.num*=10;
			X.num+=(int)(s2[i]-'0');
	 	}
	 	else if(s2[i]>='A'&&s2[i]<='F')
	 	{
	 		X.pos=(int)(s2[i]-'A')+1;
 		}
	}
	
	//situation 2
	if(check2()==true)pai=1;
	//situation 3
	if(check3()==true)tc=1;
	//situation 4
	if(check3()==true&&check4()==true)lin=1;
	cout<<cx<<pai<<tc<<lin<<endl;
	fclose(stdin);
	fclose(stdout);
 	return 0;
}

