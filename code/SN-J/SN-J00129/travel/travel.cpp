#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool a[4];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	a[0]=(c1==c2);
	a[1]=(a[0]&&(s1[0]==s2[0]&&s1[1]==s2[1]));
	a[2]=(a[1]&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')));
	a[3]=(a[2]&&(abs(s1[2]-s2[2])==1||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')));
	for(int i=0;i<4;i++)cout<<int(a[i]);
	return 0;
}
