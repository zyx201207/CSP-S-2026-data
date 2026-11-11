#include<bits/stdc++.h>
using namespace std;
int a,b,x,y,f;
char a1,b1;
string st1,st2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>st1>>b>>st2;
	x=st1[0]*10+st1[1];
	y=st2[0]*10+st2[1];
	a1=st1[2];
	b1=st2[2];
	if(a==b){
		if(x==y){
			if(a1<'D'&&b1<'D'){
				if((int)a1+1==b1||(int)b1+1==a1)f=4;
				else f=3;
			}
			else f=2;
			if(a1>'C'&&b1>'C')f=4;
			else f=2;
		}
		else f=1;
	}
	for(int i=1;i<=4;i++){
		if(f){
			cout<<1;
			f--;
		}
		else cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}              