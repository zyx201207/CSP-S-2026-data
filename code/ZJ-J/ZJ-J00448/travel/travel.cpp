#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	a=c1[0]*10+c1[1];
	b=c2[0]*10+c2[1];
	if(a==b){
		cout<<1;
		a=s1[0]*10+s1[1];
		b=s2[0]*10+s2[1];
		if(a==b){
			cout<<1;
			char x=s1[2];
			char y=s2[2];
			if((x<='C' && y<='C') || (x>='D' && y>='D')){
				cout<<1;
				if(x+1==y || y+1==x){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else{
				cout<<0<<0;
			}
		}
		else{
			cout<<0<<0<<0;
		}
	}
	else{
		cout<<0<<0<<0<<0;
	}
	return 0;
}
