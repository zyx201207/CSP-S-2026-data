#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ll n,m,k,l;
	char a,c; 
	cin>>n>>m>>a>>k>>l>>c;
	if(n==k){
		cout<<1;
		if(m==l){
			cout<<1;
			if((a=='A'&&(c=='B'||c=='C'))||(a=='B'&&(c=='A'||c=='C'))||(a=='C'&&(c=='B'||c=='A'))||(a=='D'&&c=='F')||(a=='F'&&c=='D')){
				cout<<1;
				if((a=='A'&&c=='B')||(a=='B'&&(c=='A'||c=='C'))||(a=='C'&&c=='B')||(a=='D'&&c=='F')||(a=='F'&&c=='D')){
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
