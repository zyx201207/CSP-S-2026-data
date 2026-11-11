#include<bits/stdc++.h>
using namespace std;
int n,m;
string sa,sb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>sa>>m>>sb;
	if(n==m){
		cout<<1;
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(sa[0]==sb[0]&&sa[1]==sb[1]){
		cout<<1;
	}else{
		cout<<0<<0<<0;
		return 0;
	}
	if(sa[2]>='A'&&sa[2]<='C'){
		if(sb[2]>='A'&&sb[2]<='C'){
			cout<<1;
			if(sa[2]=='B'||sb[2]=='B'){
				cout<<1;
			}else{
				cout<<0;
			}
		}else{
			cout<<0<<0;
		}
	}else if(sa[2]=='D'||sa[2]=='F'){
		if(sb[2]=='D'||sb[2]=='F'){
			cout<<11;
		}else{
			cout<<0<<0;
		}
	}
	return 0;
} 
