#include<bits/stdc++.h>
#define ll long long
using namespace std;
string sa,sb,sc,sd;
char ka,kb;
bool check1(char x,char y){
	return ((x=='D'||x=='F')&&(y=='D'||y=='F'))||((x=='A'||x=='B'||x=='C')&&(y=='A'||y=='B'||y=='C'));
}
bool check2(char x,char y){
	if(x>y)swap(x,y);
	if(x=='A'&&y=='B')return true;
	if(x=='B'&&y=='C')return true;
	if(x=='D'&&y=='F')return true;
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	cin>>sa>>sb>>sc>>sd;
	ka=sb[2];kb=sd[2];
	if(sa==sc){
		cout<<"1";
		if(sb[0]==sd[0]&&sb[1]==sd[1]){
			cout<<"1";
			if(check1(ka,kb)==1){
				cout<<"1";
				if(check2(ka,kb)==1)cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
