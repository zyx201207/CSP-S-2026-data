#include <bits/stdc++.h>
using namespace std;
string s,n,m,k;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s>>n>>m>>k;
	if(s==m){
		cout<<1;
		if(n[0]==k[0]&&n[1]==k[1]&&n!=k){
			cout<<1;
			if((n[2]<='C'&&k[2]<='C')||(n[2]>='D'&&k[2]>='D')){
				cout<<1;
				if((abs(n[2]-k[2])==1&&(n[2]<='C'&&k[2]<='C'))||((n[2]>='D'&&k[2]>='D')&&abs(n[2]-k[2])==2))cout<<1;
				else cout<<0;
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}

