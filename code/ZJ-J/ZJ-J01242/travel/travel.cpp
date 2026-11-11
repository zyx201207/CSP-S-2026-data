#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string r1,r2,x1,x2;
	bool f1=0,f2=0,f3=0;
	cin>>r1>>r2>>x1>>x2;
	int x=max( int(r2[2]),int(x2[2]) );
	int y=min( int(r2[2]),int(x2[2]) );
	if(r1==x1){
		cout<<1;
		f1=1;
	}
	else cout<<0;
	if(r2[0]==x2[0]&&r2[1]==x2[1]&&f1){
		cout<<1;
		f2=1;
	}
	else cout<<0;
	if( f2&&(x<='C'||y>='D') ){
		cout<<1;
		f3=1;
	}
	else cout<<0;
	if(f3&&((x=='B'&&y=='A')||(x=='B'&&y=='C')||(x=='F'&&y=='D'))){
		cout<<1;
	}
	else cout<<0;
	return 0;
}
