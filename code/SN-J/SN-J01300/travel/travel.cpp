#include<bits/stdc++.h>
using namespace std;
using ll = long long;
string s1,s2;
string a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s1>>b>>s2;
	if(a==b){
		cout<<1;
		if(s1.substr(0,2)==s2.substr(0,2)){
			cout<<1;
			char c1=s1[2],c2=s2[2];
			if((c1=='F'&&c2=='D')||(c1=='D'&&c2=='F')){
				cout<<11;
				return 0;
			}
			else if((c1>='A'&&c1<='C')&&(c2>='A'&&c2<='C')){
				cout<<1;
				if(c1==c2+1||c2==c1+1){
					cout<<1;
				}
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
