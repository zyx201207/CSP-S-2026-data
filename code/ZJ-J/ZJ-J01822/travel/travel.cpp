#include<bits/stdc++.h>
using namespace std;
string a,b,x,y,q,w;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>x>>b>>y;
	if(a == b&&a!="01"&&a!="16") cout<<"1";
	else{
		cout<<"0000";	
		return 0;
	}
	for(int i = 0;i<=1;i++) q+=x[i],w+=y[i];
	if(q == w) cout<<"1";
	else{
		cout<<"000";	
		return 0;
	}
	if(x[2]<='C'&&x[2]>='A'&&y[2]<='C'&&y[2]>='A') cout<<"1";
	else if(x[2]>='D'&&x[2]<='F'&&y[2]>='D'&&y[2]<='F') cout<<"1";
	else{
		cout<<"00";	
		return 0;
	}
	if(abs(int(x[2])-int(y[2])) == 1) cout<<"1";
	else cout<<"0";
	return 0;
}

