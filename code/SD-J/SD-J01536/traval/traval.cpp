#include<bits/stdc++.h>
using namespace std;
string a,b,n,m;
int sum=0;
int main(){
	freopen("traval.in","r",stdin);
	freopen("traval.out","w",stdout);
	cin>>n>>a>>m>>b;
	if(n==m)cout<<"1";
	else {cout<<"0000"<<endl;return 0;}
	for(int i=0;i<2;i++){
		if(a[i]==b[i])sum++;
	}
	if(sum==2)cout<<"1";
	else {cout<<"000"<<endl;return 0;}
	if((a[2]<='C' && a[2]>='A' && b[2]<='C' && b[2]>='A') || (a[2]=='D' && b[2]=='F') || (a[2]=='F' && b[2]=='D')){
		cout<<"1";
	}
	else {cout<<"00";return 0;}
	if((a[2]=='A' && b[2]=='B') || (a[2]=='B' && b[2]=='C') || (a[2]=='D' && b[2]=='F') || (a[2]=='F' && b[2]=='D') || (a[2]=='C' && b[2]=='B') || (a[2]=='B' && b[2]=='A')){
		cout<<"1"<<endl;
	}
	else {cout<<"0";return 0;}
	return 0;
}
