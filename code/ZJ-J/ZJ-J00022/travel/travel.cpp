#include<bits/stdc++.h>
#define N 1000010
#define int long long
using namespace std;
int c1,c2;string s1,s2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)cout<<"0000";
	else{
		cout<<"1";
		if(s1[0]!=s2[0]||s1[1]!=s2[1])cout<<"000";
		else{
			cout<<"1";
			int x,y;
			if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')x=1;
			else x=2;
			if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')y=1;
			else y=2;
			if(x!=y)cout<<"00";
			else{
				cout<<"1";
				int i,j;
				if(s1[2]>='A'&&s1[2]<='D')i=s1[2]-'A';
				else i=4;
				if(s2[2]>='A'&&s2[2]<='D')j=s2[2]-'A';
				else j=4;
				if(((i==j+1)||(j==i+1))&&(!((i==2
				&&j==3)||(i==3&&j==2))))cout<<"1";
				else cout<<"0";
			}
		}
	}
}
//by wild cat