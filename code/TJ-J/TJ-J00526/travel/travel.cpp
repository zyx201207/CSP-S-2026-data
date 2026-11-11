#include <iostream>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char d[5],n[5],p,d1[5],n1[5],p1;
	for(int i=1;i<=2;i++)
		cin>>d[i];
	for(int i=1;i<=3;i++)
		cin>>n[i];
	for(int i=1;i<=2;i++)
		cin>>d1[i];
	for(int i=1;i<=3;i++)
		cin>>n1[i];
		
	if(d[1]==d1[1]&&d[2]==d1[2])
		cout <<"1";
	else{
		cout <<"0000";
		return 0;
	}
		
	if(n[1]==n1[1]&&n[2]==n1[2]){
		cout <<"1";
		if(((n[3]=='A'||n[3]=='B'||n[3]=='C')&&(n1[3]=='A'||n1[3]=='B'||n1[3]=='C'))||((n[3]=='D'||n[3]=='F')&&(n1[3]=='D'||n1[3]=='F'))){
			cout<<"1";
			if(((n[3]=='A'&&n1[3]=='B')||(n[3]=='B'&&n1[3]=='C')||(n[3]=='C'&&n1[3]=='B')||(n[3]=='B'&&n1[3]=='A'))||((n[3]=='D')&&(n[3]=='E')||((n[3]=='E')&&(n[3]=='D')))){
				cout <<"1";
			}
			else{
				cout <<"0";
				return 0;
			}
		}
		else{
			cout <<"00";
			return 0;
		}
	}
	else{
		cout <<"000";
		return 0;
	}
	return 0;
}
