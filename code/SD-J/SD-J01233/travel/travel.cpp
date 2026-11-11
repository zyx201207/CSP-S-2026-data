#include<bits/stdc++.h>
using namespace std;
string c,s,cc,ss;
char a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>s>>cc>>ss;
	for(int i=0;i<=1;i++){
		if(c[i]!=cc[i]){
			cout<<"0000";
			return 0;
		}
	}
	cout<<"1";
	for(int i=0;i<=1;i++){
		if(s[i]!=ss[i]){
			cout<<"000";
			return 0;
		}
	}
	cout<<"1";
	if((s[2]<='C'&&ss[2]>='D')||(s[2]>='D'&&ss[2]<='C')){
		cout<<"00";
		return 0;
	}
	cout<<"1";
	a=s[2],b=ss[2];
	if(a>b) swap(a,b);
	if(b=='C'&&a=='A'){
		cout<<"0";
		return 0;
	}
	cout<<"1";
	return 0;
}
