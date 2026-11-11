#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
char s1[10],s2[10],e,f;
//#define fr(x) freopen(#x".in","r",stdin)
//#define fw(x) freopen(#x".out","w",stdout)
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s1>>b>>s2;
//	cout<<a<<' '<<s1<<' '<<b<<' '<<s2<<'\n';
	c=(s1[0]-'0')*10+(s1[1]-'0');
	d=(s2[0]-'0')*10+(s2[1]-'0');
	e=s1[2],f=s2[2];
//	cout<<a<<' '<<b<<' '<<c<<' '<<d<<' '<<e<<' '<<f<<'\n';
	if(a==b){
		cout<<"1";
		if(c==d){
			cout<<"1";
			if('A'<=e&&e<='C'&&'A'<=f&&f<='C'){
				cout<<"1";
				if(abs(e-f)==1)cout<<"1";
				else cout<<"0";
			}else if((e=='D'||e=='F')&&(f=='D'||f=='F')){
				cout<<"11";
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}
	else cout<<"0000";
	return 0;
}
