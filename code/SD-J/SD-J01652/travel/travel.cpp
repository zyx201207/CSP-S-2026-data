#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
bool c,d,e,f;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>b1>>a2>>b2;
	if(a1==a2){
		c=true;
		if(b1[0]==b2[0] && b1[1]==b2[1]){
			d=true;
			if((b1[2]>'C' && b1[2]>'C') || (b1[2]<='C' && b2[2]<='C')){
				e=true;
				if(abs(b1[2]-b2[2])==1){
					f=true;
				}
			}
		}
	}
	cout<<c<<d<<e<<f<<endl;
	return 0;
}
