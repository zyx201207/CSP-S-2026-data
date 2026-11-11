#include <bits/stdc++.h>
using namespace std;
int kao(char a,char b){
	if (a=='A' && b=='B'){
		return 1;
	}else if (a=='B' && (b=='A' || b=='c')){
		return 1;
	}else if (a=='C' && b=='B'){
		return 1;
	}else if (a=='D' && b=='F'){
		return 1;
	}else if (a=='F' && a=='D'){
		return 1;
	}else{
		return 0;
	}
}
int ce (char a,char b){
	if ((a=='A' || a=='B' || a=='C') && (b=='D' || b=='F')){
		return 0;
	} else if ((b=='A' || b=='B' || b=='C') && (a=='D' || a=='F')){
		return 0;
	}else{
		return 1;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int xiangx,xiangy;
	string zuox,zuoy;
	cin>>xiangx>>zuox>>xiangy>>zuoy;
	int numx=0,numy=0;
	for (int i=0;i<=1;i++){
		numx+=10*(zuox[i]-'0');
		numy+=10*(zuoy[i]-'0');
	}
	int f1=0,f2=0,f3=0,f4=0;
	if (xiangx==xiangy){
		cout<<1;
		f1=1;
	}else{
		cout<<0;
	}
	if (numx==numy && f1){
		cout<<1;
		f2=1;
	}else{
		cout<<0;
	}
	if (f2 && ce(zuox[2],zuoy[2])){
		cout<<1;
		f3=1;
	}else{
		cout<<0;
	}
	if (f3 && kao(zuox[2],zuoy[2])){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
