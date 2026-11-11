#include<bits/stdc++.h> 
using namespace std;
int a,b;
string am,bm; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>am>>b>>bm;
	if(a==b){
		cout<<1;
		if(am[0]==bm[0]&&am[1]==bm[1]){
			cout<<1;
			if((am[2]>='A'&&am[2]<='C'&&bm[2]>='A'&&bm[2]<='C')||(am[2]>='D'&&am[2]<='E'&&bm[2]>='D'&&bm[2]<='E')){
				cout<<1;
				if(am[2]==bm[2]+1||am[2]==bm[2]-1){
					cout<<1;
				}else cout<<0;
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000"; 
	return 0;
}
