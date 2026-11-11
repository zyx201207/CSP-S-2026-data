#include<bits/stdc++.h>
using namespace std;
#define int long long
char rc1,rc2,r1,r2,r3,xc1,xc2,x1,x2,x3;
bool pan(char r,char x){
	//位于过道的同一侧
	if((r=='D' && x=='F') || (r=='F' && x=='D')){
		return true;
	}
	if((r=='A' && x=='B') || (r=='B' && x=='A')){
		return true;
	}
	if((r=='B' && x=='C') || (r=='C' && x=='B')){
		return true;
	}
	if((r=='A' && x=='C') || (r=='C' && x=='A')){
		return true;
	}
	return false;
}
bool pan2(char r,char x){
	//相邻 
	if((r=='D' && x=='F') || (r=='F' && x=='D')){
		return true;
	}
	if((r=='A' && x=='B') || (r=='B' && x=='A')){
		return true;
	}
	if((r=='B' && x=='C') || (r=='C' && x=='B')){
		return true;
	}
	return false;
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rc1>>rc2>>r1>>r2>>r3>>xc1>>xc2>>x1>>x2>>x3;
	int rc=(rc1-'0')*10+rc2-'0';
	int xc=(xc1-'0')*10+xc2-'0';
	int rs=(r1-'0')*10+r2-'0';
	int xs=(x1-'0')*10+x2-'0';
	if(rc==xc){
		cout<<1;
	} else{
		cout<<0;
	}
	if(rc==xc && rs==xs){
		cout<<1;
	} else{
		cout<<0;
	}
	if(rc==xc && rs==xs && pan(r3,x3)){
		cout<<1;
	} else{
		cout<<0;
	}
	if(rc==xc && rs==xs && pan2(r3,x3)){
		cout<<1;
	} else{
		cout<<0;
	}
	cout<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
