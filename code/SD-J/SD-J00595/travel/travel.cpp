#include <iostream>
using namespace std;
int t1=0,t2=0;
string c1,s1,c2,s2;
bool a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1==c2) a=1;
	if (a==1 and s1[0]==s2[0] and s1[1]==s2[1]) b=1;
	if (b){
		if (s1[2]=='F' or s1[2]=='D') t2++;
		if (s2[2]=='F' or s2[2]=='D') t2++;
		if (s1[2]=='A' or s1[2]=='B' or s1[2]=='C') t1++;
		if (s2[2]=='A' or s2[2]=='B' or s2[2]=='C') t1++;
		if (t1==2 or t2==2) c=1;
	}
	if (c){
		char c1=char(min(s1[2],s2[2])),c2=char(max(s1[2],s2[2]));
		if (c1=='A' and c2=='B') d=1;
		else if ((c1=='B' and c2=='C') or (c1=='D' and c2=='F')) d=1;
	}
	cout << a << b << c << d;
	return 0;
}
