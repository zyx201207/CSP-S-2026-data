#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c1=0,c2=0;
char a[5],b[5];
void side(char m,char n){
	if((m<='C'&&n<='C')||((m>'C'&&m<='F')&&(n>'C'&&n<='F'))){
		cout<<1;
		char m1,n1;
		if(m<n)m1=m,n1=n;
		else m1=n,n1=m;
		if((m1=='A'&&n1=='B')||(m1=='B'&&n1=='C')||(m1=='D'&&n1=='F'))cout<<1;
		else cout<<0;
	}
	else cout<<"00";
}
void line(char a1,char a2,char b1,char b2){
	if((a1==b1)&&(a2==b2)){
		cout<<1;
		side(a[3],b[3]);
	}
	else cout<<"000";
}
void cx(int x,int y){
	if(x==y){
		cout<<1;
		line(a[1],a[2],b[1],b[2]);
	}
	else cout<<"0000";
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c1;
	for(int i=1;i<=3;i++)cin>>a[i];
	cin>>c2;
	for(int i=1;i<=3;i++)cin>>b[i];
	cx(c1,c2);
	return 0;
}

