#include<bits/stdc++.h>
using namespace std;
int f[4]={1,1,1,1};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int a1,a2,b1,b2;
	a1=(c1[0]-'0')*10+c1[1]-'0';
	a2=(c2[0]-'0')*10+c2[1]-'0';
	if(a1!=a2)
		f[0]=0;
	b1=(s1[0]-'0')*10+s1[1]-'0';
	b2=(s2[0]-'0')*10+s2[1]-'0';
	if(b1!=b2||!f[0])
		f[1]=0;
	if(!(((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'))&&f[1]))
		f[2]=0;
	if(!(abs(s1[2]-s2[2])==1&&f[2]))
		f[3]=0;
	cout<<f[0]<<f[1]<<f[2]<<f[3];
	return 0;
}
