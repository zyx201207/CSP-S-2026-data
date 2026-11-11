#include<iostream>
using namespace std;
#define ll long long
const int N=2e5+10;
char c1[10],c2[10],c3[10],c4[10];
int a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c1>>c2>>c3>>c4;
	int c1_=(c1[1]-'0')*10+(c1[0]-'0');
	int c3_=(c3[1]-'0')*10+(c3[0]-'0');
	if(c1_==c3_){
		a=1;
		int c2_=(c2[1]-'0')*10+(c2[0]-'0');
		int c4_=(c4[1]-'0')*10+(c4[0]-'0');
		if(c2_==c4_){
			b=1;
			if(c2[2]>='A'&&c2[2]<='C'){
				if(c4[2]>='A'&&c4[2]<='C'){
					c=1;
					if((c2[2]=='A'&&c4[2]=='C')||(c2[2]=='C'&&c4[2]=='A'))d=0;
					else{d=1;}
				}
			}
			if(c2[2]>='D'&&c2[2]<='E'){
				if(c4[2]>='D'&&c4[2]<='E'){
					c=1,d=1;
				}
			}
		}
	}
	cout<<a<<b<<c<<d;
	return 0;
}
