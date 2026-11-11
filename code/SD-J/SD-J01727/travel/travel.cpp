#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,c3,c4;
	char c02,c04;
	cin>>c1>>c2>>c02>>c3>>c4>>c04;
	if(c1==c3){
		cout<<1;
		if(c2==c4){
			cout<<1;
			if((c02=='D'&&c04=='E')||(c02=='E'&&c04=='D')||(c02=='C'&&(c04=='B'||c04=='A'))||(c02=='B'&&(c04=='C'||c04=='A'))||(c02=='A'&&(c04=='B'||c04=='C'))){
				cout<<1;
				if((c02=='C'&&c04=='A')||(c02=='A'&&c04=='C')){
					cout<<0;
				}else{
					cout<<1;
				}
			}else{
				cout<<0<<0;
			}
		}else{
			cout<<0<<0<<0;
		}
	}else{
		cout<<0<<0<<0<<0;
	}
}
