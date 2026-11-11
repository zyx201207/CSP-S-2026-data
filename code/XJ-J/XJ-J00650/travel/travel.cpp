#include<bits/stdc++.h>
using namespace std;
char a[10],b[10],c[10],d[10];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a[0]==c[0]&&a[1]==c[1]) cout<<"1";
	else {
		cout<<"0000";
		return 0;
	}
	if(b[0]==d[0]&&b[1]==d[1]) cout<<"1";
	else
	{
		cout<<"000";
		return 0;
	}
	int x=b[2]-'A'+1,y=d[2]-'A'+1;
	//cout<<endl<<x<<y<<endl;
	if((x>3&&y>3)||(x<4&&y<4)) cout<<"1";
	else{
		cout<<"00";
		return 0;
	}
	int i=b[2]-d[2];
	if(abs(i)==1||(x==4&&y==6)) cout<<"1";
	else cout<<"0";
	return 0;
}