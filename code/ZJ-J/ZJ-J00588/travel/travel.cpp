#include<bits/stdc++.h>
using namespace std;
char c1[10],s1[10],c2[10],s2[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1[1]>>c1[2]>>s1[1]>>s1[2]>>s1[3]>>c2[1]>>c2[2]>>s2[1]>>s2[2]>>s2[3];
	int a=0,b=0,c=0,d=0;
	if(c1[1]==c2[1]&&c1[2]==c2[2]) a=1;
	if(a==1&&s1[1]==s2[1]&&s1[2]==s2[2]) b=1;
	if(a==1&&b==1&&((int(s1[3])<=67&&int(s2[3])<=67)||(int(s1[3])>67&&int(s2[3])>67))) c=1;
	if(a==1&&b==1&&c==1&&((int(s1[3])+1==int(s2[3]))||(int(s1[3])==int(s2[3])+1))) d=1;
	cout<<a<<b<<c<<d;
	return 0;
}
