//姜承宇 西安翱翔中学 SN-J00653
#include<bits/stdc++.h>
using namespace std;
#define int long long
int cr,sr,cx,sx;
char ar,ax;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cr>>sr>>ar>>cx>>sx>>ax;
	if(cr == cx){
		cout<<1;
		if(sr == sx){
			cout<<1;
			if(ar>='A' and ar<='C' and ax>='A' and ax<='C' or ar>='D' and ar<='F' and ax>='D' and ax<='F'){
				cout<<1;
				if(abs(ar-ax) == 1){
					cout<<1;
				}else cout<<0;
			}else cout<<"00";
		}else cout<<"000";
	}else{
		cout<<"0000";
	}
	return 0;
}
