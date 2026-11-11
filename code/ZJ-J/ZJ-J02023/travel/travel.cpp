#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool b1,b2,b3,b4;
int t1,t2;
int main(){
	freopen("travel.in","r",stdin);freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)b1=1;
	else b1=0;
	if(s1[0]==s2[0]&&s1[1]==s2[1])b2=1;
	else b2=0;
	if(s1[2]<='C')t1=1;else t1=2;
	if(s2[2]<='C')t2=1;else t2=2;
	if(t1==t2)b3=1;else b3=0;
	if(abs(int(s1[2])-int(s2[2]))==1)b4=1;else b4=0;
	if(b1)cout<<1;else cout<<0;
	if(b1&&b2)cout<<1;else cout<<0;
	if(b1&&b2&&b3)cout<<1;else cout<<0;
	if(b1&&b2&&b3&&b4)cout<<1;else cout<<0;
	fclose(stdin);fclose(stdout);
	return 0;
}
