#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
map<char,int>sd;
int ne[6][6];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	sd['A']=1;
	sd['B']=1;
	sd['C']=1;
	sd['D']=2;
	sd['F']=2;
	ne[0][1]=ne[1][0]=1;
	ne[1][2]=ne[2][1]=1;
	ne[3][5]=ne[5][3]=1;
	cin>>a>>b>>c>>d;
	if(a==c)cout<<1;
	else cout<<0;
	if(a==c&&(b[0]=d[0])&&(b[1]==d[1]))cout<<1;
	else cout<<0;
	if(a==c&&(b[0]=d[0])&&(b[1]==d[1])&&(sd[b[2]]==sd[d[2]]))cout<<1;
	else cout<<0;
	if(a==c&&(b[0]=d[0])&&(b[1]==d[1])&&(sd[b[2]]==sd[d[2]])&&(ne[b[2]-'A'][d[2]-'A']==1))cout<<1;
	else cout<<0;
	return 0;
}
