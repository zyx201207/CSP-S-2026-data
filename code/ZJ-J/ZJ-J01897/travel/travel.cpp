#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#define int long long
using namespace std;
int a,b,c,d,b1,d1;char s[10],s1[10],s2[10],s3[10];
main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s>>s1>>s2>>s3;
	a=(s[0]-'0')*10+s[1]-'0';
	b=(s1[0]-'0')*10+s1[1]-'0';b1=s1[2]-'A'+1;
	c=(s2[0]-'0')*10+s2[1]-'0';
	d=(s3[0]-'0')*10+s3[1]-'0';d1=s3[2]-'A'+1;
	if(a==c){
		cout<<"1";
		if(b==d){
			cout<<"1";
			if((b1<=3&&d1<=3)||(b1>=4&&d1>=4)){
				cout<<"1";
				if(b1==d1+1||b1==d1-1||d1==b1+1||d1==b1-1) cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
