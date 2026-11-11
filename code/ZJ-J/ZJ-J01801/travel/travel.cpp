#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	bool f1,f2,f3,f4;
	f1=(c1==c2);
	f2=(s1.substr(0,2)==s2.substr(0,2));
	f3=(s1[2]<='C'&&s2[2]<='C')||
	(s1[2]>='D'&&s2[2]>='D');
	f4=(abs((int)(s1[2]-s2[2]))==1);
	if(f1) 
		cout<<"1";
	else cout<<"0";
	if(f1&&f2)
		 cout<<"1";
	else cout<<"0";
	if(f1&&f2&&f3)
		cout<<"1";
	else cout<<"0";
	if(f1&&f2&&f3&&f4) 
		cout<<"1";
	else cout<<"0";
	fclose(stdin);
	fclose(stdout);
	return 0;
}