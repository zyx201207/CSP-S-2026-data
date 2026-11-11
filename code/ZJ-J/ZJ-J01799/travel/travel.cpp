#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
char x,y;
int a,b;
bool check(char xx,char yy){
	if((x=='A'&&y=='B')||(x=='B'&&y=='A')||(x=='B'&&y=='C')||(x=='C'&&y=='B')||(x=='D'&&y=='F'))return 1;
	return 0;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		a=int(s1[0]-48)*10+int(s1[1]-48);
		b=int(s2[0]-48)*10+int(s2[1]-48);
		if(a==b){
			cout<<1;
			x=s1[2];
			y=s2[2];
			if((x=='A'&&(y=='B'||y=='C'))||(x=='B'&&(y=='A'||y=='C'))||(x=='C'&&(y=='A'||y=='B'))||(x=='D'&&y=='F')||(x=='F'&&y=='D')){
				cout<<1;
				if(check(x,y))cout<<1;
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}