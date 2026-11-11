#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string x,y,a,b;cin>>x>>a>>y>>b;
	if(x==y){
		if(a[0]==b[0]&&a[1]==b[1]){
			char s1=a[2],s2=b[2];
			if(s1>s2) swap(s1,s2);
			if(s1=='A'&&s2=='B') cout<<"1111\n";
			else if(s1=='A'&&s2=='C') cout<<"1110\n";
			else if(s1=='B'&&s2=='C') cout<<"1111\n";
			else if(s1=='D'&&s2=='F') cout<<"1111\n";
			else cout<<"1100\n";
		}
		else cout<<"1000\n";
	}
	else cout<<"0000\n";
	return 0;
}

