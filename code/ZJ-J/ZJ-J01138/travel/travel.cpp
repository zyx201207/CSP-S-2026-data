#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,i,j,k,l,x,t,z,s,g,h;
char a[5],b[5],c[5],d[5];
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a+1>>b+1>>c+1>>d+1;
	if(a[1]==c[1]&&a[2]==c[2]){
		cout<<"1";
		if(b[1]==d[1]&&b[2]==d[2]){
			cout<<"1";
			if(b[3]<='C'&&d[3]<='C'||b[3]>='D'&&d[3]>='D'){
				cout<<"1";
				if(abs(b[3]-d[3])==1) cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}