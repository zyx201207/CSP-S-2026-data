#include<bits/stdc++.h>
using namespace std;
int a,b;
string sa,sb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>sa>>b>>sb;
	if(a==b){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	a=((int)(sa[0]-'0')*10+(int)(sa[1]-'0'));
	sa=sa[2];
	b=((int)(sb[0]-'0')*10+(int)(sb[1]-'0'));
	sb=sb[2];
	if(a==b){
		cout<<1;
		if((('A'<=sa[0]&&sa[0]<='C')&&('A'<=sb[0]&&sb[0]<='C'))||(('D'<=sa[0]&&sa[0]<='F')&&('D'<=sb[0]&&sb[0]<='F'))){
			cout<<1;
			if(sa[0]+1==sb[0]||sb[0]+1==sa[0]){
				cout<<1;
			}else{
				cout<<0;
			}
		}else{
			cout<<"00";
		}
	}else{
		cout<<"000";
		return 0;
	}
	
	return 0;
}
