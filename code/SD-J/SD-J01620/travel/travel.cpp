#include<bits/stdc++.h>
using namespace std;

bool side(char c){
	if(c=='D'||c=='E') return 1;
	else return 0;
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string sitR,sitX,numR,numX;
	cin>>numR>>sitR>>numX>>sitX;
	if(numR==numX) cout<<1;
	else cout<<0;
	if(numR==numX&&sitR[0]==sitX[0]&&sitR[1]==sitX[1]) cout<<1;
	else cout<<0;
	if(numR==numX&&sitR[0]==sitX[0]&&sitR[1]==sitX[1]&&side(sitR[2])==side(sitX[2])) cout<<1;
	else cout<<0;
	if(numR==numX&&sitR[0]==sitX[0]&&sitR[1]==sitX[1]&&side(sitR[2])==side(sitX[2])&&abs(int(sitR[2])-int(sitX[2]))==1) cout<<1;
	else cout<<0;
}
