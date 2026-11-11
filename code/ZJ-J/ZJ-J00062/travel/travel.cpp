#include<bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	
	bool x=0;
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		cout<<1;
		x=1;
	}
	else cout<<0;
	
	bool ok=0;
	if(x==1&&s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
		ok=1;
	}
	else cout<<0;
	
	bool p=0;
	if(x==1&&ok==1&&((s1[2]<='C'&&s1[2]>='A'&&s2[2]<='C'&&s2[2]>='A')||(s1[2]<='F'&&s1[2]>='D'&&s2[2]<='F'&&s2[2]>='D'))){
		cout<<1;
		p=1;
	}
	else cout<<0;
	
	if(x==1&&ok==1&&p==1&&(((s1[2]+1==s2[2]||s2[2]+1==s1[2])&&s1[2]<='C'&&s1[2]>='A'&&s2[2]<='C'&&s2[2]>='A')||((s1[2]+2==s2[2]||s2[2]+2==s1[2]))&&(s1[2]<='F'&&s1[2]>='D'&&s2[2]<='F'&&s2[2]>='D'))){
		cout<<1;
	}
	else cout<<0;
	
	return 0;
}
