#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int k;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(int(a[1])==int(c[1]) && int(a[0])==int(c[0])){
		k=1;
		cout<<1;	
	}else cout<<0;
	if(int(b[0])==int(d[0]) && int(b[1])==int(d[1]) && k==1){
		k=1;
		cout<<1;
	}else{
		k=0;
		cout<<0;
	}
	if((((b[2]=='A' || b[2]=='B' || b[2]=='C') && (d[2]=='A' || d[2]=='B' || d[2]=='C')) || ((b[2]=='D' || b[2]=='F') && (d[2]=='D' || d[2]=='F'))) && k==1){
		k=1;
		cout<<1;
	}else{
		k=0;
		cout<<0;
	}
	if(abs(int(b[2])-int(d[2]))==1 && k==1){
		cout<<1;
	}else cout<<0;
	return 0; 
} 
