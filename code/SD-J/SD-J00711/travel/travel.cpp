#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char s1[4],s2[4];int c1,c2;
	cin>>c1;
	for(int i=0;i<3;i++)cin>>s1[i];
	cin>>c2;
	for(int i=0;i<3;i++)cin>>s2[i];
	if(c1 !=c2) cout<<0<<0<<0<<0;
	else if(s1[0]-'0' !=  s2[0] -'0' || s1[1]-'0'!=s2[1]-'0')cout<<1000;
	else if(!(s1[2]-'A'<3 && s2[2]-'A'<3 || 
	s1[2]-'A'>3 && s2[2]-'A'<3))cout<<1100;
	else if((s1[2]-'A')-(s2[2]-'A')!=1 && 
			(s1[2]-'A')-(s2[2]-'A')!=-1)cout<<1110;
	else cout<<1111;
	return 0;
}

