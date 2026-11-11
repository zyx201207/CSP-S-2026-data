#include<bits/stdc++.h>
using namespace std;

int c,cc;
string s,ss;
bool flag=1;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>c>>s>>cc>>ss;
	if(c==cc) cout<<1;
	else{
		cout<<0;
		flag=0;
	}
	if(s[0]==ss[0]&&s[1]==ss[1]&&flag) cout<<1;
	else{
		cout<<0;
		flag=0; 
	}
	if((s[2]<='C'&&ss[2]<='C'&&flag)||(s[2]>='D'&&ss[2]>='D'&&flag)) cout<<1;
	else{
		cout<<0;
		flag=0;
	}
	if(flag&&((s[2]+1==ss[2])||(ss[2]+1==s[2]))) cout<<1;
	else cout<<0;
	
	return 0;
} 
