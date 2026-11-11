#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char c,d;
	cin>>c>>d;
	int a=(c-'0')*10+d-'0';
	cin>>c>>d;
	int b=(c-'0')*10+d-'0';
	cin>>c;
	int x=c-'A'+1;
	cin>>c>>d;
	int cc=(c-'0')*10+d-'0';
	cin>>c>>d;
	int dd=(c-'0')*10+d-'0';
	cin>>c;
	int y=c-'A'+1;
	if(a==cc){
		cout<<1;
		if(b==dd){
			cout<<1;
			if(x<=3&&y<=3||x>=4&&y>=4){
				cout<<1;
				if(abs(x-y)==1||x==4&&y==6||x==6&&y==4){
					cout<<1;
				}
				else{
					cout<<"0";
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
	else{
		cout<<"0000";
	}
	return 0;
}