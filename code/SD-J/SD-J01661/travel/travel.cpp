#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a,b;
string s,s1;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s>>b>>s1;
	if(a!=b){
		cout<<"0000";
		return 0;
	}
	else{
		int c=0,d=0;
		c=c*10+s[0];
		c=c*10+s[1];
		d=d*10+s1[0];
		d=d*10+s1[1];
		if(c!=d){
			cout<<"1000";
			return 0;
		}
		else{
			char ss=s[2],ss1=s1[2];
			int e,f;
			if((ss<='C'&&ss1<='C')||(ss>='D'&&ss1>='D')){
				e=ss-'A',f=ss1-'A';
			}
			else{
				cout<<"1100";
				return 0;
			}
			if((ss<='C'&&ss1<='C'&&abs(e-f)==1)||(ss>='D'&&ss1>='D')){
				cout<<"1111";
				return 0;
			}
			else{
				cout<<"1110";
				return 0;
			}
		}
	}
	return 0;
}
