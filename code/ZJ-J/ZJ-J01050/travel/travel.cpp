#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int r,c1,x,c2; char s1,s2;
	cin>>r>>c1>>s1>>x>>c2>>s2;
	if(r==x){
		if(c1==c2){
			if(s1<='C'&&s2<='C'||s1>'C'&&s2>'C'){
				if(abs(s1-s2)<2){
					cout<<1111;
				}
				else{
					cout<<1110;
				}
			}
			else{
				cout<<1100;
			}
		}
		else{
			cout<<1000;
		}
	}
	else{
		cout<<0000;
	}
	return 0;
}