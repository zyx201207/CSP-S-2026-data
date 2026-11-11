#include <iostream>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,c3,c4;
	cin>>c1>>c2>>c3>>c4;
	if(c1==c3){
		cout<<"1";
		if(c2[0]==c4[0]&&c2[1]==c4[1])
		{
			cout<<"1";
			if(int(c2[2])>=65&&int(c2[2])<=67&&int(c4[2])>=65&&int(c4[2])<=67)
			{
				cout<<"1";
				if(int(c2[2]+1)==int(c4[2])||int(c2[2]-1)==int(c4[2])) cout<<"1";
				else cout<<"0";
			}
			else if(int(c2[2])>=68&&int(c2[2])<=69&&int(c4[2])>=68&&int(c4[2])<=69)
			{
				cout<<"1";
				if(int(c2[2]+1)==int(c4[2])||int(c2[2]-1)==int(c4[2])) cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000"; 
	return 0;
	fclose(stdin);
	fclose(stdout);
 } 
