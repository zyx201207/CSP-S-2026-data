#include <bits/stdc++.h>
#define Trick 8
#define Treat 8
using namespace std;
int c1,c2;
string s1,s2;
int side[]={0,0,0,1,1};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1==c2){
		putchar('1');
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			putchar('1');
			if(side[s1[2]]==side[s2[2]]){
				putchar('1');
				if(side[s1[2]]==1||s1[2]=='B'||s2[2]=='B')
					cout << 1;
				else
					cout << 0;
			}
			else
				puts("00");
		}
		else
			puts("000");
	}
	else
		puts("0000");
	return Trick^Treat;
}
