#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
char zuo1,zuo2;
int main(){
	freopen("travel.in","r",stdin);freopen("travel.out","w",stdout);
	cin>>a;
	cin>>b;
	cin>>zuo1;
	cin>>c;
	cin>>d;
	cin>>zuo2;
	if(a!=c){
		cout<<0<<0<<0<<0;
		return 0;
	}
	else{
		cout<<1;
		if(b!=d){
			cout<<0<<0<<0;
			return 0;
		}
		else{
			cout<<1;
			if((zuo1>'C'&&zuo2>'C')||(zuo1<='C'&&zuo2<'C')){
				cout<<1;
				if(!(zuo1+1==zuo2 || zuo1-1==zuo2)){
					cout<<0;
				}
				else{
					cout<<1;
				}
			}
			else{
				cout<<0<<0;
			}
		}
	}
	return 0;
}

