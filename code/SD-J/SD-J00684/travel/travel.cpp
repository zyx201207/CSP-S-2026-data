#include<bits/stdc++.h>
using namespace std;
string x,x2,y,y2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x>>x2>>y>>y2;
	if(x[0]==y[0]&&x[1]==y[1])
	{
		cout<<1;
	}else cout<<0;
	if(x2[0]==y2[0]&&x2[1]==y2[1]&&x[0]==y[0]&&x[1]==y[1])
	{
		cout<<1;
	}else cout<<0;
	if(x2[0]==y2[0]&&x2[1]==y2[1]&&x[0]==y[0]&&x[1]==y[1])
	{
		if(((x2[2]-y2[2]==1||x2[2]-y2[2]==-1)||(x2[2]=='C'&&y2[2]=='A')||(x2[2]=='A'&&y2[2]=='C'))&&((x2[2]!='C'||y2[2]!='D')&&(x2[2]!='D'||y2[2]!='C')))
			cout<<1;
		else cout<<0;
	}else cout<<0;
	
	if(x2[0]==y2[0]&&x2[1]==y2[1]&&x[0]==y[0]&&x[1]==y[1])
	{
		if((x2[2]-y2[2]==1||x2[2]-y2[2]==-1)&&(x2[2]!='C'&&y2[2]!='D')&&(x2[2]!='D'&&y2[2]!='C'))
			if((x2[2]-y2[2]==1||x2[2]-y2[2]==-1)&&(x2[2]!='C'||y2[2]!='D')&&(x2[2]!='D'||y2[2]!='C'))
				cout<<1;
			else cout<<0;
		else cout<<0;
	}else cout<<0;
	return 0;
}
