#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,c,d;
	char x,y;
	cin>>a>>b>>x>>c>>d>>y;
	if(a==c){
		cout<<1;
		if(b==d){
			cout<<1;
			if((x<='C'&&y<='C')||(x>='D'&&y>='D')){
				cout<<1;
				if(abs(x-y)==1){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}