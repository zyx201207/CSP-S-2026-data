#include<bits/stdc++.h>
using namespace std;
string c1,c2,d1,d2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>d1>>d2	;
	if(c1==d1)
	{
		cout<<1;
		if(d2[0]==c2[0]&&c2[1]==d2[1])
		{
			cout<<1;
			if(c2[2]<='C'&&d2[2]<='C')
				{
					cout<<1;
					if(abs(int(c2[2]-d2[2]))==1)
						cout<<1;
					else
						cout<<0;
				}
			else if(c2[2]>='D'&&d2[2]>='D')
			{
				cout<<11;
			}else
				cout<<"00";
			}	
		else
			cout<<"000";
		}
	else {
		cout<<"0000";
	}
	return 0;
} 
