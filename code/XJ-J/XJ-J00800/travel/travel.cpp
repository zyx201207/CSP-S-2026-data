#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string che1;
	string che2;
	string cc1;
	string cc2;
	cin>>che1>>cc1>>che2>>cc2;
	if(che1.compare(che2)==0){
		cout<<1;
		if(cc1[0]==cc2[0]&&cc1[1]==cc2[1]){
			cout<<1;
			if(cc1[2]>='D'&&cc1[2]<='E'&&cc2[2]>='D'&&cc2[2]<='E'){
				cout<<1<<1;
			}
			if(cc1[2]>='A'&&cc1[2]<='C'&&cc2[2]>='A'&&cc2[2]<='C'){
				cout<<1;
				if(cc1[2]=='A'&&cc2[2]=='B'||cc1[2]=='B'&&cc2[2]=='A'||cc1[2]=='B'&&cc2[2]=='C'||cc1[2]=='C'&&cc2[2]=='B')
				{
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else{
				cout<<0<<0;
			}
		}
		else{
			cout<<0<<0<<0;
		}
	}
	else{
		cout<<0<<0<<0<<0;
	}
return 0;
}