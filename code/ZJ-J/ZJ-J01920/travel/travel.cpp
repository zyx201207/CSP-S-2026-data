#include<bits/stdc++.h>
using namespace std;
#define ll long long
string c1,s1,c2,s2;
ll x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<c1.size();i++) x+=c1[i]-'0';
	for(int i=0;i<c2.size();i++) y+=c2[i]-'0';
	if(x==y){
		cout<<"1";
		ll a=0,b=0;
		for(int i=0;i<2;i++) a+=s1[i]-'0';
		for(int i=0;i<2;i++) b+=s2[i]-'0';
		if(a==b){
			cout<<"1";
			char c=s1[2],cc=s2[2];
			if((c=='A'||c=='B'||c=='C')&&(cc=='A'||cc=='B'||cc=='C')){
				cout<<"1";
				if(c=='A'&&cc=='C'||c=='C'||cc=='A'){
					cout<<"0\n";
				}else{
					cout<<"1\n";
				}
			}else if((c=='D'||c=='E')&&(cc=='D'||cc=='E')){
				cout<<"11\n";
			}else{
				cout<<"00\n";
			}
		}else{
			cout<<"000\n";
		}
	}else cout<<"0000\n";
	return 0;
}
