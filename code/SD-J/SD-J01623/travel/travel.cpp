#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    bool flag=0;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		if(c1=="01"||c1=="16") cout<<"0";
		else{
		    cout<<"1";
			flag=1;	
		}
	}
	else cout<<"0";
	if(!flag){
		cout<<"000";
		return 0;
	}
	if(s1[0]+s1[1]==s2[0]+s2[1])
	{
		cout<<"1";
		char a=s1[2],b=s2[2];
		if(((a>='A'&&a<='C')&&(b>='A'&&b<='C'))||((a>='D'&&a<='E')&&(b>='D'&&b<='E')))
		cout<<"1";
		else cout<<"0";
		if((a>='D'&&a<='E')&&(b>='D'&&b<='E')) cout<<"1";
		else if(a=='A'&&b=='C') cout<<"0";
		else if(a=='C'&&b=='A') cout<<"0";
		else if(a=='C'&&b=='D') cout<<"0";
		else if(a=='D'&&b=='C') cout<<"0";
		else cout<<"1";
	}
	else cout<<"000";
	
	

    return 0;
}


