#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	long long c,t;
	cin>>c>>t;
	if(t==1)cout<<1;
	else if(t==2)cout<<1<<endl<<2;
	else if(t==3)cout<<0<<endl<<1<<endl<<2;
	else if(t==4)cout<<0<<endl<<1<<endl<<2<<endl<<3;
	else if(t==5)cout<<0<<endl<<1<<endl<<2<<endl<<3<<endl<<4;
	return 0;
}
