#include<bits/stdc++.h>
#define int long long
#define INF 1145141919810
using namespace std;
int c11,c22;
string s1,s2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c11>>s1>>c22>>s2;
	if(c11!=c22)cout<<"0000";
	else{
		cout<<"1";
		if(s1[0]!=s2[0]||s1[1]!=s2[1])cout<<"000";
		else{
			cout<<"1";
			char c1=s1[2],c2=s2[2];
			if(c1>c2)swap(c1,c2);
			if((c1=='A'||c1=='B'||c1=='C')&&(c2=='D'||c2=='F'))
				cout<<"00";
			else{
				cout<<"1";
				if(c1=='A'&&c2=='B')cout<<"1";
				else if(c1=='B'&&c2=='C')cout<<"1";
				else if(c1=='D'&&c2=='F')cout<<"1";
				else cout<<"0";
			}
		}
	}
	return 0;
}