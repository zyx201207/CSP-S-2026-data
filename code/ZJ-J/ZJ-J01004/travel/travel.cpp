#include<bits/stdc++.h>
#define int long long
#define FIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	FIO
	string c1,s1,c2,s2;
	char t1,t2;
	int x,y;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2) cout<<"0000";
	else{
		cout<<"1";
		x=(s1[0]-'0')*10+s1[1]-'0',y=(s2[0]-'0')*10+s2[1]-'0';
		if(x!=y) cout<<"000";
		else{
			cout<<"1";
			t1=s1[2],t2=s2[2];
			if(((t1=='A'||t1=='B'||t1=='C')&&(t2=='A'||t2=='B'||t2=='C'))||((t1=='D'||t1=='F')&&(t2=='D'||t2=='F'))){
				cout<<"1";
				if(abs(t1-t2)==1) cout<<1;
				else cout<<"0";
			}
			else cout<<"00";
		}
	}
	return 0;
}