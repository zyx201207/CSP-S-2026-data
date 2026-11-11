#include<bits/stdc++.h>

using namespace std;

#define int long long

string a,b;
char aa,aaa,bb,bbb,q,w;
bool f;

signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>aa>>aaa>>q>>b>>bb>>bbb>>w;
	if(a == b){
		cout<<'1';
	}else{
		cout<<"0000";
		return 0;
	}
	if(aa == bb && aaa == bbb){
		cout<<'1';
	}else{
		cout<<"000";
		return 0;
	}
	if(q + w == 'D' + 'E'){
		cout<<'1';
		f = 1;
	}
	if(q != 'D' && q != 'E' && w != 'D' && w != 'E'){
		cout<<'1';
		f = 1;
	}
	if(f == 0){
		cout<<"00";
		return 0;
	}
	if(q + 1 == w || q-1 == w){
		cout<<'1';
	}else{
		cout<<'0';
	}
	return 0;
} 
