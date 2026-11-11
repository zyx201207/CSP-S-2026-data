#include<bits/stdc++.h>
using namespace std;
int a,b;
string aa,bb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>aa;
	cin>>b>>bb;
	if(a==b){
		int x,y;
		x=aa[0]*10+aa[1];
		y=bb[0]*10+bb[1];
		if(x==y){
			int c1=aa[2],c2=bb[2];
			if((c1>='A' && c1<='C' && c2>='A' && c2<='C') || (c1>='D' && c2<='E' && c2>='E' && c2<='F')){
				if(abs(int(c2-c1))==1)cout<<"1111\n";
				else cout<<"1110\n";
			}
			else cout<<"1100\n";
		}
		else{
			cout<<"1000\n";
		}
	}
	else cout<<"0000\n";
	return 0;
} 
