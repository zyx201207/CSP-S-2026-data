#include<bits/stdc++.h>
using namespace std;
string c[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<=4;i++)cin>>c[i];
	if(c[1]==c[3]){
		cout<<1;
		
		if(c[2].substr(0,2)==c[4].substr(0,2)){
			cout<<1;
			if((c[2][2]>='D' && c[4][2]>='D') || (c[2][2]<='C' && c[4][2]<='C')){
				cout<<1;
				if(abs(c[2][2]-c[4][2])<=1){
					cout<<1;
				}else{
					cout<<0;
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
	
	
	return 0;
}
