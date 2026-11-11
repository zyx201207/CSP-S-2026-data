#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int ra,xa;
	string rb,xb;

	cin>>ra>>rb>>xa>>xb;
	if(ra==xa){
		cout<<1;
		if(rb[0]==xb[0]&&rb[1]==xb[1]){
			cout<<1;
		if((rb[2]<=67&&xb[2]<=67)||(rb[2]>67&&xb[2]>67)){
			cout<<1;
			if(rb[2]+1==xb[2]||rb[2]-1==xb[2]||xb[2]+1==rb[2]||xb[2]-1==rb[2]){
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
 
