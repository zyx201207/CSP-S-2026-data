#include<bits/stdc++.h>
using namespace std;
bool ans1,ans2,ans3,ans4;
string c1,s1,c2,s2,p1="",p2="";
char a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	p1+=s1[0];
	p1+=s1[1];
	p2+=s2[0];
	p2+=s2[1];
	a=max(s1[2],s2[2]);
	b=min(s1[2],s2[2]);
	if(c1==c2) ans1=1;
	if(ans1&&p1==p2) ans2=1;
	if(ans2&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'))) ans3=1;
	if(ans3&&(a-b==1)) ans4=1;
	cout<<ans1<<ans2<<ans3<<ans4;
	return 0;
}
