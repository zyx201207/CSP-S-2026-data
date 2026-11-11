#include<bits/stdc++.h>
using namespace std;
int a[200005];
char b[200005],qwq;
bool is=true;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	qwq=b[1];
	for(int i=1;i<=n;i++){
		if(b[i]!=qwq){
			is=false;
			break;
		}
	}
	if(n==1 or is==true){
		cout<<0;
	}
	else{
		cout<<2;
	}
}
