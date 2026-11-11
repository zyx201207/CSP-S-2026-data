#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	
	string ra,rb,xa,xb;
	cin>>ra>>rb>>xa>>xb;
	
	if(ra==xa){
		cout<<1;
		
		char a,b;
		for(ll i=0;i<rb.length();++i){
			if(rb[i]>='A'&&rb[i]<='Z'){
				a=rb[i];
				rb[i]=' ';
			}	
		}
		
		for(ll i=0;i<xb.length();++i){			
			if(xb[i]>='A'&&xb[i]<='Z'){
				b=xb[i];
				xb[i]=' ';
			}	
		}
		
		if(rb==xb){
			cout<<1;
			if((a>='A'&&a<='C'&&b>='A'&&b<='C')||(a>='D'&&a<='E'&&b>='D'&&b<='E')){
				cout<<1;
			}else{
				cout<<0;
			}
				
			if(a<b){
				swap(a,b);
			}
				
			if(a!='D'&&b!='C'&&a-b==1){
				cout<<1;
			}else{
				cout<<0;
			}
		}else{
			cout<<0<<0<<0;
		}
			
			
			
//		cout<<ra<<' '<<xa<<'\n'<<rb<<' '<<xb<<'\n'<<a<<' '<<b;
	}else{
		cout<<0<<0<<0<<0;
	}
	
	
	return 0;
}
