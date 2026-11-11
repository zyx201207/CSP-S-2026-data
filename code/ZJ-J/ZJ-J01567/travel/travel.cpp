#include<bits/stdc++.h>
//#define int long long 
using namespace std;
int c1,c2;
string s1,s2;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			int flag1=0,flag2=0;
			char p1=s1[2],p2=s2[2];
			int f=p1-'A',f2=p2-'A';
			if(p1=='A'||p1=='B'||p1=='C') flag1=1;
			if(p2=='A'||p2=='B'||p2=='C') flag2=1;
			if(flag1==flag2){
				cout<<1;
				if(abs(f-f2)==1) cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}