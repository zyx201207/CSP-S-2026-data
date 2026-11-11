
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","out",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<1;
	   else {
	   		cout<<000;
	   		return 0;
	   }
	bool liyang=false;
	for(int i=0;i<2;i++)
	{
		if(s1[i]==s2[i])liyang=true;
					else{
						cout<<"000";
						return 0;
					} 
	}
	if(liyang==true)cout<<1;
	if((s1[2]>='A'&&s1[2]<='C')&&(s2[2]>='A'&&s2[2]<='C'))cout<<"1";
		if((s1[2]>='D'&&s1[2]<='F')&&(s2[2]>='D'&&s2[2]<='F'))cout<<"1";
															else cout<<"00";
	if(abs(s1[2]-s2[2])==1)cout<<1;
					else   cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
