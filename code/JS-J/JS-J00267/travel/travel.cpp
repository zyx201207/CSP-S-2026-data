#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool f=0,l=0,k=0;
	if(c1==c2){
		cout<<1;
		k=1;
	}
	else cout<<0;
	int a=(s1[0]-'0')*10+(s1[1]-'0');
	int b=(s2[0]-'0')*10+(s2[1]-'0');
	if(k&&a==b){
		cout<<1;
		l=1;
	}
	else cout<<0;
	if(l&&((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F'))){
		cout<<1;
		f=1;
	}
	else cout<<0;
	if(f){
		if(s1[2]==s2[2]-1||s1[2]==s2[2]+1) cout<<1;
		else cout<<0;
	}
	else cout<<0;
	return 0;
}
