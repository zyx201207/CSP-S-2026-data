#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,s1,s2;
	char a,b;
	cin>>c1>>s1>>a>>c2>>s2>>b;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	if(s1!=s2){
		cout<<"000";
		return 0;
	}
	cout<<1;
	if(a>'A'-1&&a<'D'&&b>'A'-1&&b<'D'){
		cout<<1;
		if(abs(a-b)==1)cout<<1;
		else cout<<0;
	}
	else if(a>'C'&&a<'G'&&b>'C'&&b<'G'){
		cout<<1;
		if(abs(a-b)==1)cout<<1;
		else cout<<0;
	}
	else cout<<"00";
	return 0;
}

