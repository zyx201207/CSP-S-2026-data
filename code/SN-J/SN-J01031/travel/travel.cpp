#include <bits/stdc++.h>
using namespace std;
long long read(){
	long long ans = 0,f = 1;
	char ch = getchar();
	while(!isdigit(ch)){
		if(ch=='-') f = -1;
		ch = getchar();
	}
	while(isdigit(ch)){
		ans = ans*10+ch-'0';
		ch = getchar();
	}
	return ans*f;
}

string r1,r2,c1,c2,ans;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r1>>r2>>c1>>c2;
	r1 == c1 ? ans += '1' : ans += '0';
	if(r2[0]==c2[0]&&r2[1]==c2[1]) ans += '1';
	else ans += '0';
	if((r2[2]=='A'||r2[2]=='B'||r2[2]=='C')&&(c2[2]=='A'||c2[2]=='B'||c2[2]=='C')) ans += '1';
	else if((r2[2]=='D'||r2[2]=='F')&&(c2[2]=='D'||c2[2]=='F')) ans += '1';
	else ans += '0';
	if(r2[2]=='A'&&c2[2]=='B') ans += '1';
	else if(r2[2]=='B'&&c2[2]=='C') ans += '1';
	else if(r2[2]=='B'&&c2[2]=='A') ans += '1';
	else if(r2[2]=='C'&&c2[2]=='B') ans += '1';
	else if(r2[2]=='D'&&c2[2]=='F') ans += '1';
	else if(r2[2]=='F'&&c2[2]=='D') ans += '1';
	else ans += '0';
	cout<<ans;
	
	
	return 0;
}//--std=c++14 -Wl --stack=536870912
