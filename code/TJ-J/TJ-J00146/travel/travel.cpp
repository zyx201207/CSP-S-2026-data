#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m;cin>>n;
	string s1,s2;cin>>s1;
	cin>>m;cin>>s2;
	if(n==m){
		cout<<1;
		int c1=(s1[0]+'0')*10+(s1[1]+'0');
		int c2=(s2[0]+'0')*10+(s2[1]+'0');
		if(c1==c2){
			cout<<1;
			if(!((s1[2]=='C' && s2[2]=='D')||(s1[2]=='D' && s2[2]=='C'))){
				cout<<1;
				if(s1[2]+1==s2[2] || s1[2]-1==s2[2]){
					cout<<1;
				}
				else cout<<0;
			}
			else cout<<0<<0;
		} 
		else cout<<0<<0<<0;
	}
	else cout<<0<<0<<0<<0;
	
	
	return 0;
} 
