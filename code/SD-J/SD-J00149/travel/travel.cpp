#include<bits/stdc++.h>
using namespace std;
int c1,l1,c2,l2;
char s1,s2; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c1>>l1>>s1;
	cin>>c2>>l2>>s2;
	if(c1!=c2) cout<<"0000";
	else if(l1!=l2) cout<<"1000";
	else if(((s1<='C')^(s2<='C'))) cout<<"1100";
	else if(abs(int(s1-s2))==1||(s1=='D'&&s2=='F')||(s1=='F'&&s2=='D')) cout<<"1111";
	else cout<<"1110";
	return 0;
} 
