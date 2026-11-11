#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int ans,sum;
int a1,b1,c1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	for(int i=1;i<=2;i++){
		if(a[i]==c[i]){
			ans++;
		}
		
	}
//	for(int i=1;i<=2;i++){
//		if(b[i]==d[i]){
//			sum++;
//		}
//	}
	if(ans==2){
		a1=1;
		cout<<a1;
	}
	else{
		cout<<0;
	}
	if(b[1]==d[1]&&b[2]==d[2]&&b[3]!=d[3]){
		b1=1;
		cout<<b1;
	}
	else{
		cout<<0;
	}
	if((b[3]=='F'&&d[3]=='D')||(b[3]=='D'&&d[3]=='F')||(b[3]=='A'&&d[3]=='B')||
	(b[3]=='B'&&d[3]=='A')||(b[3]=='B'&&d[3]=='C')||(b[3]=='C'&&d[3]=='B')||
	(b[3]=='A'&&d[3]=='C')||(b[3]=='C'&&d[3]=='A')){
		c1=1;
		cout<<c1;
	}
	else{
		cout<<0;
	}
	if(a1==1&&c1==1){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
} 
