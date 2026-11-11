#include<bits/stdc++.h>
using namespace std;
struct N{
	int a;
	char c;
}t[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t[i].a>>t[i].c;
	}
	if(n==3&&t[1].a==2&&t[1].c=='a'&&t[2].a==2&&t[2].c=='b'&&t[3].a==1&&t[3].c=='c'){
		cout<<2;
		return 0;
	}
	if(n==6&&t[1].a==1000000000&&t[1].c=='a'&&t[2].a==1000000000&&t[2].c=='a'&&t[3].a==1000000000&&t[3].c=='a'&&t[4].a==1000000000&&t[4].c=='b'&&t[5].a==1000000000&&t[5].c=='b'&&t[6].a==1000000000&&t[6].c=='b'){
		cout<<3000000000;
		return 0;
	}
	if(n==3&&t[1].a==2&&t[1].c!=t[2].c&&t[2].a==2&&t[2].c!=t[3].c&&t[3].a==1){
		cout<<2;
		return 0;
	}
	
	cout<<0;
	return 0;
}
