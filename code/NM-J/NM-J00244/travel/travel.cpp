#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main()
{
	//ºÃ³óÂªµÄ´úÂë 
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
    int s11=int(s1[0]),s12=int(s1[1]),s21=int(s2[0]),s22=int(s2[1]);
    int s1c=int(s1[2]),s2c=int(s2[2]);
    if(c1==c2)
    {
        cout<<1;
    }
    else
    {
        cout<<"0000"<<endl;
        return 0;
    }
    
    if(s11==s21 && s12==s22)
    {
         cout<<1;
    }
    else
    {
        cout<<0;
    }
    int sa=int(s1[1]*10)+int(s1[2]);
	int sb=int(s2[1]*10)+int(s2[2]);
	if((s11==s21 && s12==s22 && s1c>=65 and s1c<=67 and s2c>=65 and s2c<=67) or (s11==s21 && s12==s22 and s1c>=68 and s1c<=69 and s2c>=68 and s2c<=69))
	{
		cout<<1;
		
	}
	else
	{
		cout<<0;
		
	}
	if(((s11==s21 && s12==s22 && s1c>=65 and s1c<=67 and s2c>=65 and s2c<=67) or (s11==s21 && s12==s22 and s1c>=68 and s1c<=69 and s2c>=68 and s2c<=69)) and (sa==(sb+1) || sa==(sb-1) || sb==(sa-1) || sb==(sa+1)))
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}


    return 0;
}
