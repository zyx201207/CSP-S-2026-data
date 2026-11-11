#include<bits/stdc++.h>
using namespace std;
int s,q;
string s1,q1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s;
	cin>>s1;
	cin>>q;
	cin>>q1;
	if((s1[1]==1||(s1[1]==6&&s1[0]==1))||(q1[1]==1||(q1[1]==6&&q1[0]==1))){
		cout<<"0000";
		return 0;
	}
	if(s==q){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==q1[0]&&s1[1]==q1[1]){
		cout<<1;
	} else{
		cout<<"000";
		return 0;
	}
	if(((s1[2]>='A'&&s1[2]<='C')&&(q1[2]>='A'&&q1[2]<='C'))||((s1[2]>='D'&&s1[2]<='F')&&(q1[2]>='D'&&q1[2]<='F'))){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if((s1[2]>='D'&&s1[2]<='F')&&(q1[2]>='D'&&q1[2]<='F')){
		cout<<1;
	}else if(s1[2]-1==q1[2]||s1[2]+1==q1[2]){
		cout<<1;
	}else{
		cout<<"0";
		return 0;
	}
	return 0;
}
