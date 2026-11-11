#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int r[10],x[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	r[0]=(c1[0]-'0')*10+(c1[1]-'0');
	x[0]=(c2[0]-'0')*10+(c2[1]-'0');
	r[1]=(s1[0]-'0')*10+(s1[1]-'0');
	x[1]=(s2[0]-'0')*10+(s2[1]-'0');
	r[2]=s1[2]-'A'+1;
	x[2]=s2[2]-'A'+1;
	if (r[2]==6){
		r[2]=5;
	}
	if (x[2]==6){
		x[2]=5;
	}
	bool flag1=(r[0]==x[0]);
	bool flag2=(r[1]==x[1]);
	bool flag3=((r[2]<=3&&x[2]<=3)||(r[2]>=4&&x[2]>=4));
	bool flag4=(abs(r[2]-x[2])==1);
	cout<<flag1;
	cout<<(flag1&&flag2);
	cout<<(flag1&&flag2&&flag3);
	cout<<(flag1&&flag2&&flag3&&flag4);
	return 0;
}