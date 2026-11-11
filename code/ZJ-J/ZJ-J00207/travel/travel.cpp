#include<bits/stdc++.h>
using namespace std;
char s1,s2;
int c1,c2,x1,x2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>x1>>s1>>c2>>x2>>s2;
	if(c1==c2) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(x1==x2) cout<<1;
	else{
		cout<<"000";
		return 0;	
	}
	if((s1>='A'&&s1<='C'&&s2>='A'&&s2<='C')||(s1>='D'&&s1<='F'&&s2>='D'&&s2<='F')) cout<<1;
	else{
		cout<<"00";
		return 0;
	}
    if((s1=='A'&&s2=='B')||(s1=='B'&&s2=='A')||(s1=='B'&&s2=='C')||(s1=='C'&&s2=='B')||(s1=='D'&&s2=='F')||(s1=='F'&&s2=='D')) cout<<1;
    else cout<<0;
    return 0;
}