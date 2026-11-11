#include<bits/stdc++.h>
using namespace std;
#define ll long long
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,x,y;
	cin>>a>>x>>b>>y;
	if(a!=b){
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	int n,m;
	n=(x[0]-'0')*10+(x[1]-'0');
	m=(y[0]-'0')*10+(y[1]-'0');
	if(n==m){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	if((x[2]=='D'&&y[2]=='F')||(x[2]=='F'&&y[2]=='D')){
		cout<<"11";return 0;
	}else if(x[2]=='D'||y[2]=='D'||x[2]=='F'||y[2]=='F'){
		cout<<"00"; return 0;
	}else{
		cout<<"1";
		if((x[2]=='C'&&y[2]=='A')||(y[2]=='C'&&x[2]=='A')){
			cout<<"0";
		}else cout<<"1";
	}
	return 0;
}

