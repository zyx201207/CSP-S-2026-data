#include<bits/stdc++.h>
using namespace std;
#define int long long
string a,b,c,d; 
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<"1";
		if(b[0]!=d[0]||b[1]!=d[1]){
			cout<<"000";
			return 0;
		}
		else{
			cout<<"1";
			int flag=0;
			if(b[2]=='A'||b[2]=='B'||b[2]=='C'){
				if(d[2]=='D'||d[2]=='F')
					flag=1;
			}
			if(b[2]=='D'||b[2]=='F'){
				if(d[2]=='A'||d[2]=='B'||d[2]=='C')
					flag=1;
			}
			if(flag==0)
				cout<<"1";
			else{
				cout<<"00";
				return 0;	
			}
			if(abs(b[2]-d[2])==1){
				cout<<"1";
			}
			else
				cout<<"0";
		}
	}
	else 
		cout<<"0000";
	return 0;
}
