#include<bits/stdc++.h>
using namespace std;
long long a,b,ac,bc;
string s,s1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s>>b>>s1;
	if(a!=b)
		cout<<"0000";
	else{
		cout<<1;
		for(int i=0;i<2;i++){
			if(s[i]!=s1[i]){
				cout<<"000";
				return 0;
			}
		}
		cout<<1;
		if(int(s[2]-'A'-2)<=0)
			ac=0;
		else
			ac=1;
		if(int(s1[2]-'A'-2)<=0)
			bc=0;
		else
			bc=1;
		if(ac!=bc){
			cout<<"00";
			return 0;
		}
		cout<<1;
		if((s[2]=='A' && s1[2]=='C') || (s[2]=='C' && s1[2]=='A')){
			cout<<"0";
			return 0;
		}
		cout<<1;
	}
	return 0;//Score||Treat!
}
