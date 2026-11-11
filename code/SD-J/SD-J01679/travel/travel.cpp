#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,c,d;
	char e,f;
	cin>>a>>b>>e>>c>>d>>f;
	if(a==c)
	{
		cout<<"1";
		{
			if(b==d){
				cout<<"1";
				if((e<'D'&&f<'D')||(e>'C'&&f>'C')){
					cout<<"1";
					if((e+1)==f||(e-1)==f){
						cout<<"1";
					}
					else{
						cout<<0;
					}
				}
				else{
					cout<<"00";
				}
			}
			else{
				cout<<"000";
			}
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
} 
