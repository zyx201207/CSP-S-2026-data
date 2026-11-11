#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
string c,d,a,b;
cin>>a>>c>>b>>d;
if(a==b){
cout<<"1";
	if(c[0]==d[0]&&c[1]==d[1]){
		cout<<"1";
		if(c[2]<='C'&&d[2]<='C'||c[2]>='D'&&d[2]>='D'){
			cout<<"1";
			if(c[2]=='A'&&d[2]=='B'||c[2]=='B'&&d[2]=='C'||c[2]=='D'&&d[2]=='E'||c[2]=='B'&&d[2]=='A'||c[2]=='B'&&d[2]=='C'||c[2]=='E'&&d[2]=='D'){\
				cout<<"1";
			}else{
			cout<<"0";
			}
		}else{
			cout<<"00";
		}
	}else{
		cout<<"000";
	}
}else{
cout<<"0000";
}
return 0;
}
