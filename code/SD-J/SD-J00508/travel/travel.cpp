#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int a=0,b=0,c=0,d=0;
	if(c1==c2)
	{
		a=1;
		string h1="";
		char l1;
		h1+=s1[0];
		h1+=s1[1];
		l1=s1[2];
		string h2="";
		char l2;
		h2+=s2[0];
		h2+=s2[1];
		l2=s2[2];
		//同一行 
		if(h1==h2)
		{
			b=1;
			//过道同一侧 
			if(l1>='A'&&l1<='C'&&l2>='A'&&l2<='C'||l1>='D'&&l1<='F'&&l2>='D'&&l2<='F')
			{
				c=1;
				if(l1>='A'&&l1<='C')
				{
					int k=abs(l1-l2);
					if(k==1) d=1;
				} 
				else
				{
					d=1;
				}
			}
		}
	} 
	cout<<a<<b<<c<<d;
	return 0;
}

