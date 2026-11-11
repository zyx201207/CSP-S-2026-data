#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool same_row=0,beside=0,same=0;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	//question 1
	if(c1==c2){
		cout<<1;
		same=1;
	}else cout<<0,same=0;
	//question 2
	if(same&&s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
		same_row=1;
	}else cout<<0,same_row=0;
	//question 3
	if(same_row&&s1[2]<='C'&&s2[2]<='C'){
		cout<<1;
		beside=1;
	}else if(same_row&&s1[2]>='D'&&s2[2]>='D'){
		cout<<1;
		beside=1;
	}else cout<<0,beside=0;
	//question 4
	if(beside){
		if(abs(s1[2]-s2[2])==1)cout<<1;
		else cout<<0;
	}else cout<<0;
	return 0;
}

