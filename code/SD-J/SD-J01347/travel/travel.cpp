#include<bits/stdc++.h>
using namespace std;
char a[10],b[10],c[10],d[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	for(int i=1;i<=2;i++) cin>>a[i];
	for(int i=1;i<=3;i++) cin>>b[i];
	for(int i=1;i<=2;i++) cin>>c[i];
	for(int i=1;i<=3;i++) cin>>d[i];
	if(a[1]==c[1]&&a[2]==c[2]) cout<<"1";
	else{
		cout<<"0000";return 0;
	}
	if(b[1]==d[1]&&b[2]==d[2]) cout<<"1";
	else{
		cout<<"000";return 0;
	}
	if(((b[3]>='A'&&b[3]<='C')&&(d[3]>='A'&&d[3]<='C'))||((b[3]>='E'&&b[3]<='F')&&(d[3]>='E'&&d[3]<='F')))
		cout<<"1";
	else{
		cout<<"00";return 0;
	}
	if((b[3]==d[3]+1)||(b[3]==d[3]-1)) cout<<"1";
	else cout<<"0";
	return 0;
} 
