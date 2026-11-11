#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,e,f;
char x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>x>>c>>d>>y;
	e=x-'A',f=y-'A';
	if(a==c){
		cout<<1;
		if(b==d){
			cout<<1;
			if((e<3 && f<3) || (e>=3 && f>=3)){
				cout<<1;
				if(abs(e-f)==1){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
} 
