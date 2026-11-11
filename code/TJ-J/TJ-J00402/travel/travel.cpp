#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool intongce(string s1,string s2) {
	if((s1[2]=='A' or s1[2]=='B' or s1[2]=='C') and (s2[2]=='A' or s2[2]=='B' or s2[2]=='C')) return 1;
	if((s1[2]=='D' or s1[2]=='F') and (s2[2]=='D' or s2[2]=='F')) return 1;
	return 0;
}
bool isbeside(char a,char b) {
	if((a=='A' and b=='B' ) or (b=='A' and a=='B')) return 1;
	if((a=='B' and b=='C') or (b=='C' and a=='B')) return 1;
	if((a=='D' and b=='F' ) or (b=='F' and a=='D')) return 1;
	return 0;
}
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) {
		cout<<1;
	} else {
		cout<<0;
	}
	//两张车票对应的座位是否在同一节车厢
	if(c1==c2 and s1[0]==s2[0] and s1[1]==s2[1]) {
		cout<<1;
	} else {
		cout<<0;
	}
	//两张车票对应的座位是否在同一节车厢的同一排
	if(c1==c2 and s1[0]==s2[0] and s1[1]==s2[1] and intongce(s1,s2)) {
		cout<<1;
	} else {
		cout<<0;
	}
	//两张车票对应的座位是否在同一节车厢的同一排，且位于过道的同一侧
	char a=s1[2],b=s2[2];
	if(c1==c2 and s1[0]==s2[0] and s1[1]==s2[1] and isbeside(a,b)) {
		cout<<1;
	} else {
		cout<<0;
	}
	//两张车票对应的座位是否相邻。
	fclose(stdin);
	fclose(stdout);
	return 0;
}
