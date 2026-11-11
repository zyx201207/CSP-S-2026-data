#include<bits/stdc++.h>
using namespace std;
struct stru{
	int c,x,y;
}r1;
struct op{
	int c,x,y;
}r2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r1.c>>r1.x;
	char cy;
	cin>>cy;
	r1.y=cy-'A'+1;
	cin>>r2.c>>r2.x;
	cin>>cy;
	r2.y=cy-'A'+1;
	bool st=1;
	if(r1.c==r2.c){
		cout<<1;
	}else{
		st=0;
		cout<<0;
	}
	if(st&&r1.x==r2.x){
		cout<<1;
	}else{
		st=0;
		cout<<0;
	}
	bool lr;
	if(st){
		if(r1.y<=3&&r2.y<=3){
			lr=1;
			cout<<1;
		}else if(r1.y>3&&r2.y>3){
			lr=0;
			cout<<1;
		}else{
			st=0;
			cout<<0;
		}
	}else{
		st=0;
		cout<<0;
	}
	if(st&&!lr) cout<<1;
	else if(st&&abs(r1.y-r2.y)==1) cout<<1;
	else cout<<0;
	return 0;
}
