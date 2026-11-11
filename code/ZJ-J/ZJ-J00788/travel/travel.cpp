#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,a2,b,b2;
	char c,c2;
	cin>>a>>b>>c>>a2>>b2>>c2;
	bool ok=(a==a2);
	bool ok2=ok&(b==b2);
	bool ok3=ok2&((c<='C')==(c2<='C'));
	bool ok4=ok3&(abs(c-c2)==1);
	cout<<ok<<ok2<<ok3<<ok4;
}
/*
02 01A 02 01B
02 01C 02 01A
02 01C 02 01D
02 02B 02 01A
02 01A 03 01A
*/