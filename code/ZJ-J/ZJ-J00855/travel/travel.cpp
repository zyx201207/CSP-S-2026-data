#include<bits/stdc++.h>
#define int long long
using namespace std;
int c1,c2,s1,s2;
char a[1010],b[1010];
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c1>>a+1>>c2>>b+1;
    if(c1==c2){
    	s1=(a[1]-'0')*10+(a[2]-'0');
    	s2=(b[1]-'0')*10+(b[2]-'0');
    	if(s1==s2){
    		if(a[3]=='C'&&b[3]=='D'||a[3]=='D'&&b[3]=='C')cout<<"1100";
			else{
				if(abs(a[3]-b[3])==1)cout<<"1111";
				else cout<<"1110";
			}
		}
		else cout<<"1000";
	}
	else cout<<"0000";
	return 0;
}
