#include<bits/stdc++.h>
#define ll long long
using namespace std;
int x,y;
string a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x>>a>>y>>b;
	if(x!=y) cout<<"0000";
	else{
		cout<<1;
		int suma=0,sumb=0;
		suma=(a[0]-'0')*10+(a[1]-'0');
		sumb=(b[0]-'0')*10+(b[1]-'0');
		if(suma!=sumb) cout<<"000";
		else{
			cout<<1;
			if(a[2]-'A'<3&&b[2]-'A'<3||a[2]-'A'>2&&b[2]-'A'>2){
				cout<<1;
				if(abs(a[2]-b[2])==1) cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
	}
	return 0;
}

