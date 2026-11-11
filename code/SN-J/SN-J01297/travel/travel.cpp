#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
char a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else return puts("0000"),0;
	a=s1[2];
	b=s2[2];
	if(s1[1]==s2[1]&&s1[0]==s2[0]) cout<<1;
	else return puts("000"),0;
	if(a=='D'&&b=='F'||a=='F'&&b=='D') return puts("11"),0;
	if(a=='A'&&b=='C'||a=='C'&&b=='A') return puts("10"),0;
	if(a=='D'&&b=='C'||a=='C'&&b=='D') return puts("00"),0;
	puts("11");
	return 0;
}
