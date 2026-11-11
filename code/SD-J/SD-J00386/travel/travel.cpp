#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int q=(s1[0]-48)*10+(s1[1]-48),w=(s2[0]-48)*10+(s2[1]-48),a=0;
	char f=s1[2],g=s2[2];
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	else if(q!=w){
		cout<<"1000";
		return 0;
	}
	else if((((f=='A' or f=='B') or f=='C') and ((g=='A' or g=='B') or g=='C')) or ((f=='D' or f=='F') and (g=='D' or g=='F'))){
		a++;
	}
	if(a==0){
		cout<<"1100";
	}
	else if((int(f)-int(g))==1 or (int(f)-int(g))==-1){
		cout<<"1111";
	}
	else if(a==1){
		cout<<"1110";
	}
	return 0;
}
