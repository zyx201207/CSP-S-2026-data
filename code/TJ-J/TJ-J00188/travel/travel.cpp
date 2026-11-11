#include<bits/stdc++.h>
using namespace std;
bool tigd(string b1,string b2)
{
	if(b1[2]=='D'||b1[2]=='F')
	{
		if(b2[2]=='D'||b2[2]=='F')
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else if(b2[2]!='D'&&b2[2]!='F')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
bool xl(int x,int y)
{
	if(x-y==1||x-y==-1) return 1;
	return 0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,b1,a2,b2;
	int ans1=0,ans2=0,ans3=0;
	cin >>a1>>b1>>a2>>b2;    
	//1          
	if(a1==a2)
	{                                  
		cout <<1;
		ans1=1;                        
	}                                  
	else cout <<0;                       
    //2
	if(b1[0]==b2[0]&&b1[1]==b2[1]&&ans1==1)   
	{
		cout <<1;
		ans2=1;
	}
	else cout <<0; 
	//3                                  
	cout <<((ans2==1)&&tigd(b1,b2));                
	//4
	cout <<((ans2==1)&&(xl(b1[2],b2[2])&&tigd(b1,b2))); 
}
