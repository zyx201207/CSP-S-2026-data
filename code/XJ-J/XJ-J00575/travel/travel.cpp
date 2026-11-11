#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
char a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	a = s1[2];
	b = s2[2];
	if(c1 == c2){
		cout << 1;
	}else cout << 0;//first
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&c1==c2){
		cout << 1;
	}else cout << 0;//second
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		if(a=='A'&&b=='B'||a=='A'&&b=='C'||a=='B'&&b=='C'||a=='B'&&b=='A'||a=='C'&&b=='A'||a=='C'&&b=='B'){
			cout << 1;
		}else if(a=='D'&&b=='F'||a=='F'&&b=='D'){
			cout << 1;
		}else cout << 0;
	}else cout << 0;//third
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]){
		if(a=='A'&&b=='B'||a=='A'&&b=='C'||a=='B'&&b=='C'||a=='B'&&b=='A'||a=='C'&&b=='A'||a=='C'&&b=='B'){
			if(a-b==1||b-a==1){
				cout << 1;
			}else cout << 0;
		}else if(a=='D'&&b=='F'||a=='F'&&b=='D'){
			cout << 1;
		}else cout << 0;
	}else cout << 0;//last
	return 0;
}