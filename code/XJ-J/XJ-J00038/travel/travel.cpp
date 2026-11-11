#include<bits/stdc++.h>
using namespace std;
string a,b,u,v;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);cout.tie(0);
	cin>>a>>b>>u>>v;
	if(a==u){
		cout<<1;
		if(b[1]==v[1]&&b[0]==v[0]){
			cout<<1;
			if((b[2]>='A'&&b[2]<='C'&&'A'<=v[2]&&v[2]<='C')||
			('D'<=b[2]&&b[2]<='F'&&'D'<=v[2]&&v[2]<='F')){
				cout<<1;
				
				if(b[2]-v[2]==1||v[2]-b[2]==1){
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
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
} 
