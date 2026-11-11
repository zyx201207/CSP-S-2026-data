#include<bits/stdc++.h>
using namespace std;
int main()
{
 	freopen("travel.in","r",stdin);
 	freopen("travel.out","w",stdout);
	int x1,x2;
	int z1,z2;
	char c1,c2;
	cin>>x1>>z1>>c1>>x2>>z2>>c2;
	if(x1==x2){
		cout<<1;
		if(z1==z2){
			cout<<1;
			if(c1<='C'&&c2<='C'){
				cout<<1;
				if(abs((int)(c1-c2))==1){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else{
				if((c1=='D'&&c2=='F')||(c2=='D'&&c1=='F'))
				{
					cout<<11;
				}
				else{
					cout<<"00";
				}
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
 	return 0;
}
