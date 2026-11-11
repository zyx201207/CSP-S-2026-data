#include<bits/stdc++.h>
using namespace std;
long long a,b;
string c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>c>>b>>d;
	if(a==b){
		cout<<1;
		if(c[0]==d[0] and c[1]==d[1]){
			cout<<1;
			if(c[2]=='A' and d[2]=='B' or c[2]=='B' and d[2]=='A' or c[2]=='A' and d[2]=='C' or c[2]=='C' and d[2]=='A' or c[2]=='B' and d[2]=='C' or c[2]=='C' and d[2]=='B' or c[2]=='D' and d[2]=='F' or c[2]=='F' and d[2]=='D'){
				cout<<1;
				if(c[2]=='A' and d[2]=='B' or c[2]=='B' and d[2]=='A' or c[2]=='B' and d[2]=='C' or c[2]=='C' and d[2]=='B' or c[2]=='D' and d[2]=='F' or c[2]=='F' and d[2]=='D'){
					cout<<1;
				}
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
