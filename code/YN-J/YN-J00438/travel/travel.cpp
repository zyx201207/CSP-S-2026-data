#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	bool x,y,n,m;
	if(c1=c2){
		x=n=true;
	}
	else{
		x=n=false;
		if(s1=s2){
			y=m=true;
		}
	}
	cout<<x<<y<<n<<m;
	return 0;
}