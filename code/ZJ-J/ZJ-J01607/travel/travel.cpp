#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
using namespace std;
string c1,s1,c2,s2;
int calc(char x){
	if(x=='A') return 1;
	if(x=='B') return 2;
	if(x=='C') return 3;
	if(x=='D') return 4;
	return 5;
}
bool check(int x,int y){
	int a=(x>=1&&x<=3);
	int b=(y>=1&&y<=3);
	return (a==b);
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<"1";
			int x=calc(s1[2]);
			int y=calc(s2[2]);
			if(check(x,y)){
				cout<<"1";
				if(abs(x-y)==1) cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
