#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	long long n,m,q,w;
	char e,r;
	
	scanf("%lld%lld%c",&n,&q,&e);
	scanf("%lld%lld%c",&m,&w,&r);
	
	if(n==m){
		cout<<1;
		if(q==w){
			cout<<1;
			if( (r=='F' and e=='D') or (e=='F' and r=='D') ){
				cout<<11;
			}else{
				if((r=='A' and e=='B') or (r=='B' and e=='A') or (r=='B' and e=='C') or (e=='B' and r=='c')){
					cout<<11;
				}else{
					if( (r=='A' and e=='C') or (e=='A' and r=='C') ){
						cout<<1;
						cout<<0;
					}else{
						cout<<0;
						cout<<0;
					}
				}
			}	
		}else{
			cout<<0;
			cout<<0;
			cout<<0;
			
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
