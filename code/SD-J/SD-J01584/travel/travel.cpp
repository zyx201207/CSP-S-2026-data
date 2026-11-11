#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
string s1,s2,s3,s4; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>s1>>s2>>s3>>s4;
	if(s1!=s3) cout<<"0000"<<'\n';
	else{
		if(s2[0]!=s4[0]||s2[1]!=s4[1]) cout<<"1000"<<'\n';
		else{
			char c1=s2[2],c2=s4[2];
			if((c1>='A'&&c1<='C'&&c2>='D'&&c2<='F') || (c2>='A'&&c2<='C'&&c1>='D'&&c1<='F')) cout<<"1100"<<'\n';
			else{
				if(abs(c1-c2)!=1) cout<<"1110"<<'\n';
				else cout<<"1111"<<'\n';
			}
		}
	}
	return 0;
} 
