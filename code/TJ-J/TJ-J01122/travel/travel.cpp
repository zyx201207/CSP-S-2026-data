#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,same1=0,same2=0,same3=0;
	string s1,s2;
	
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2)//tongyichexiang?
	{
		cout<<1;
		same1=1;
	}
	else
	{
		cout << 0;
	}
	if(same1==0)
	{
		cout << 0;
	}
	if(same1==1)
	{
		if(s1[0]==s2[0] && s1[1]==s2[1])//tongyipai?
		{
			cout << 1;
			same2=1;
    	}
    	else if(!(s1[0]==s2[0] && s1[1]==s2[1]))//tongyipai?
		{
			cout << 0;
    	}
	}
	if(same2==0 || same1 == 0)
	{
		cout << 0;
	}
	if(same2==1)
	{
		if(s1[2] == 'A'||s1[2] == 'B'||s1[2] == 'C' && s2[2] == 'A'||s2[2] == 'B'||s2[2] == 'C')//abc yice?
		{
			cout<< 1;
			same3=1;
		}
		else if(s1[2] == 'D'||s1[2] == 'F' && s2[2] == 'D'||s2[2] == 'F')//df yice?
		{
			cout<< 1;
			same3 =1;
		}
		else if(!(s1[2] == 'A'||s1[2] == 'B'||s1[2] == 'C' && s2[2] == 'A'||s2[2] == 'B'||s2[2] == 'C'))//abc yice?
		{
			cout<< 0;
		}
		else if(!(s1[2] == 'D'||s1[2] == 'F' && s2[2] == 'D'||s2[2] == 'F'))//df yice?
		{
			cout<< 0;
		}
	} 
	if(same3==0 || same2==0 || same1 == 0)
	{
		cout << 0;
	}
	if(same3==1)
	{
		if(s1[2]+s2[2] == 131||s1[2]+s2[2] == 133||s1[2]+s2[2] == 138)//xianglin?
		{
			cout << 1;	
		}
		else if(s1[2]+s2[2] != 131||s1[2]+s2[2] != 133||s1[2]+s2[2] != 138)
		{
			cout << 0;
		}
	}
	return 0;
}
//02 01A 02 01B ---- 1111
//02 01C 02 01A ---- 1110
//02 01C 02 01D ---- 1100
//02 01A 03 01A ---- 0000
//02 02B 02 01A ---- 1000
