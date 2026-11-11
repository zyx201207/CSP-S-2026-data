#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d;
string s1,s2,n1,n2;
int main()
{
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	cin>>s1>>n1>>s2>>n2;
	if(a==b)
	{
		cout<<"1";
		if(n1[0]==n2[0]&&n1[1]==n2[1])
		{
		    cout<<"1";
		    char c1=n1[2],c2=n2[2];
		    if((c1=='A'||c1=='B'||c1=='C')&&(c2=='A'||c2=='B'||c2=='C'))
			{
			    cout<<"1";
		        if(abs(c1-c2)==1)cout<<"1";
		        else cout<<"0";
		    }
		    else cout<<"00";
		}
		else cout<<"000";
    }    
	else cout<<"0000";
    //fclose(stdin);
	//fclose(stdout);
	return 0;
}
