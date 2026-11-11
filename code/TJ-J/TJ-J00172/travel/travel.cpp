#include<bits/stdc++.h>
using namespace std;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string n,m,s1,s2;
	cin>>n>>s1>>m>>s2;
	if(n==m){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			if((65<=int(s2[2])&&int(s2[2])<=67&&65<=int(s1[2])&&int(s1[2])<=67)||(68<=int(s2[2])&&int(s2[2])<=70&&68<=int(s1[2])&&int(s1[2])<=70)){
				cout<<1;
				if(int(abs(s1[2]-s2[2]))==1)cout<<1;
				else cout<<0;
			}
			else cout<<0<<0;
		}else cout<<0<<0<<0;
	}
	else cout<<0<<0<<0<<0;
	return 0;
} 
