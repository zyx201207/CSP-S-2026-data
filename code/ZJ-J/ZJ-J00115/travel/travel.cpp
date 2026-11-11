#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	long long c1,s1;
	string c2,s2;
	cin>>c1>>c2>>s1>>s2;
	if(c1==s1){
		cout<<1;
		long long k1=(c2[0]-'0')*10+c2[1];
		long long k2=(s2[0]-'0')*10+s2[1];
		if(k1==k2){
			cout<<1;
			if((s2[2]>='D'&&c2[2]>='D')||(s2[2]<='C'&&c2[2]<='C')){
				cout<<1;
				if(abs(s2[2]-c2[2])==1) cout<<1;
				else cout<<0;
			}else{
				cout<<"00";
			}
		}
		else cout<<"000";
	} 
	else cout<<"0000";
	return 0;
} 
