#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	bool is=false,is1=false,is2=false;
	int t;
	if(c1==c2){
		cout<<1;
		is=true;
	}
	else cout<<0;
	if(is&&s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
		is1=true;
	}
	else cout<<0;
	if(is&&is1){
		if(s1[2]<='C'&&s2[2]<='C'){
			cout<<1;
			t=0;
			is2=true;
		}
		else if(s1[2]>='D'&&s2[2]>='D'){
			cout<<1;
			t=1;
			is2=true;
		}
		else cout<<0;
	}
	else cout<<0;
	if(is&&is1&&is2){
		if(t){
			cout<<1;
		}
		else if(abs(s1[2]-s2[2])==1){
			cout<<1;
		}
		else cout<<0;
	}
	else cout<<0;
	return 0;
}
