#include<bits/stdc++.h>
using namespace std;
int cx,cy,sxf,syf;
char cha,chb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cx>>sxf>>cha>>cy>>syf>>chb;
	if(cx==cy){
		cout<<1;
		if(sxf==syf){
			cout<<1;
			if((cha=='A'&&chb=='B')||(cha=='A'&&chb=='C')||(cha=='B'&&chb=='A')||(cha=='B'&&chb=='C')||(cha=='C'&&chb=='A')||(cha=='C'&&chb=='B')||(cha=='D'&&chb=='F')||(cha=='F'&&chb=='D')){
				cout<<1;
				if(abs((int)cha-(int)chb)==1) cout<<1;
				else cout<<0;
			}
			else cout<<0<<0;
		}
		else cout<<0<<0<<0;
	} 
	else cout<<0<<0<<0<<0;
	return 0;
}

