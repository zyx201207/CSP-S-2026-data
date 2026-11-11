#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+100;
int c1,c2,x1,x2;
string s1,s2;
bool b=1;
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<'1';
	else{
		cout<<'0';
		b=0;
	}
	x1=(s1[0]-'0')*10+(s1[1]-'0');
	x2=(s2[0]-'0')*10+(s2[1]-'0');
	if(b&&x1==x2) cout<<'1';
	else{
		cout<<'0';
		b=0;
	}
	if(b){
		if( (s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')){
			cout<<'1';
		}else if((s1[2]=='D'||s1[2]=='E')&&(s2[2]=='D'||s2[2]=='E')){
			cout<<'1';
		}else{
			cout<<'0';
			b=0;
		}
	}else{
		cout<<'0';
		b=0;
	}
	int t=(s1[2]-'0')-(s2[2]-'0');
	if(b&&abs(t)==1){
		cout<<'1';
	}else cout<<'0';
	return 0;
}
