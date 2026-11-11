#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,c,d;
	char m,n;
	cin>>a>>b>>m>>c>>d>>n;
	if(a!=c)cout<<"0000";
	else if(b!=d)cout<<1000;
	else if((m>=65&&m<=67)||(n==68||n==70))cout<<1100;
	else if((n>=65&&n<=67)||(m==68||m==70))cout<<1100;
	else if(m-n==1||n-m==1)cout<<1111;
	else if((m=='D'&&n=='F')||(m=='F'&&n=='D'))cout<<1111;
	else cout<<1110;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
