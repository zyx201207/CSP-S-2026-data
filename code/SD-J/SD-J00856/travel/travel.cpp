#include<bits/stdc++.h>
#define ll long long
using namespace std;
string c1,s1,c2,s2;
string ans="0000";
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		ans[0]='1';
		int z1=(s1[0]-'0')*10+(s1[1]-'0'),z2=(s2[0]-'0')*10+(s2[1]-'0');
		if(z1==z2){
			ans[1]='1';
			char h1=s1[2],h2=s2[2];
			if(h1>h2)swap(h1,h2);
			if(h1<='C'&&h2<='C'){
				ans[2]='1';
				if((h1=='A'&&h2=='B')||(h1=='B'&&h2=='C'))ans[3]='1';
			}
			if(h1>='D'&&h2>='D'){
				ans[2]='1';
				if(h1=='D'&&h2=='F')ans[3]='1';
			}
		}
	}
	cout<<ans;
	return 0;
}
