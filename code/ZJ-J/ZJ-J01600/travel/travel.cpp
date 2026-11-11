#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
string a,b,c,d;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>a>>b>>c>>d;
	if(a[0]==c[0]&&a[1]==c[1]){
		cout<<1;
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<1;
			if(b[2]=='A'||b[2]=='B'||b[2]=='C'){
				if(d[2]=='A'||d[2]=='B'||d[2]=='C'){
					cout<<1;
					if(abs(d[2]-b[2])==1){
						cout<<1;
					}
					else{
						cout<<0;
					}
				}
				else{
					cout<<"00";
				}
			}
			else{
				if(d[2]=='D'||d[2]=='E'){
					cout<<1;
					if(abs(d[2]-b[2])==1){
						cout<<1;
					}
					else{
						cout<<0;
					}
				}
				else{
					cout<<"00";
				}
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
