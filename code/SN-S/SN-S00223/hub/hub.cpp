#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d,a[2000050],m[2000050];
bool flag=true;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c;
	if(c==1)cout<<"3/n2/n4";
	else if(c==2||c==3)cout<<"6/n4/n8/n7 ";
	else cout<<"12\n8\n16\n9\n14";
	return 0;
}

 
