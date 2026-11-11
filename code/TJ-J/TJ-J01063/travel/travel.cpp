#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	int c1,s1,c2,s2;
	cin>>c1>>s1;
	cin>>c2>>s2;
	if(c1==c2)
	cout<<"1"<<"1";
	else cout<<"0"<<"0";
	if(s1!=s2)
{ 
if(('s1'==94)&&('s2'==95))
cout<<"0"<<"0";
else{

    if(('s1+1'!=s2)||('s1+2!=s2')||('s1+3!=s2')||('s1+4!=s2')||('s1+5!=s2'))
    cout<<"1"<<"1";
    else
    cout<<"0"<<"0";
	}
}
   fclose(stdin);
   fclose(stdout);
    return 0;
}
