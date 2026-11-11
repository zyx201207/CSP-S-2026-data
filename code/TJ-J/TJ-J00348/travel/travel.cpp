#include<bits/stdc++.h>
using namespace std;
#define ll long long
string cr,sr,cx,sx,s1,s2;
char c1,c2;
bool check(char flag1,char flag2){
	if (c1==flag1 && c2==flag2 || c1==flag2 && c2==flag1){
		return 1;
	}return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>cr>>sr>>cx>>sx;
	if (cr==cx){

	}else{
		cout<<"0000"<<"\n";
		return 0;
	}s1=sr[0]+sr[1];s2=sx[0]+sx[1];
	if (s1==s2){

	}else{
		cout<<"1000"<<"\n";
		return 0;
	}c1=sr[2],c2=sx[2];
	if (check('A','B') || check('A','C') || check('B','C') || check('D','F')){

	}else{
		cout<<"1100"<<"\n";
		return 0;
	}if (check('A','C')){
		cout<<"1110"<<"\n";
	}else{
		cout<<"1111"<<"\n";
	}
	return 0;
}

