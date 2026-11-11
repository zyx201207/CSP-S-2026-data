#include<bits/stdc++.h>
using namespace std;
struct no{
	int id,a;
	char s;
}x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x.id>>x.a>>x.s;
	cin>>y.id>>y.a>>y.s;
	if(x.id==y.id){
		if(x.a==y.a){
			if((x.s=='A'||x.s=='B'||x.s=='C')&&(y.s=='A'||y.s=='B'||y.s=='C')){
				if(x.s=='A'&&y.s=='C'||y.s=='A'&&x.s=='C'){
					cout<<"1110";
				}
				else{
					cout<<"1111";
				}
			}
			else if((x.s=='D'||x.s=='F')&&(y.s=='D'||y.s=='F')){
				if(x.s=='A'&&y.s=='C'||y.s=='A'&&x.s=='C'){
					cout<<"1110";
				}
				else{
					cout<<"1111";
				}
			}
			else{
				cout<<"1100";
			}
		}
		else{
			cout<<"1000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
} 
