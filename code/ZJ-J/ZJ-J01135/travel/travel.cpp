#include <bits/stdc++.h>
using namespace std;
int x,y,e,f,fl;
char a[5],b[5],c[5],d[5];
bool pd(){
	if(abs(x-y)>=4) return 0;
	if(b[3]=='C'&&d[3]=='D'||d[3]=='C'&&b[3]=='D') return 0;
	if(b[3]=='C'&&d[3]=='F'||d[3]=='C'&&b[3]=='F') return 0;
	return 1;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a+1>>b+1>>c+1>>d+1;
	if(a[1]==c[1]&&a[2]==c[2]) cout<<1,e=1;
	else cout<<0;
	if(e==1&&b[1]==d[1]&&b[2]==d[2]) cout<<1,f=1;
	else cout<<0;
	x=b[3]-'A';y=d[3]-'A';
	if(f==1&&e==1&&pd()) cout<<1;
	else cout<<0;
	if(b[1]==d[1]&&b[2]==d[2]) fl=1;
	if(fl==1&&abs(x-y)==1){
		if(b[3]=='C'&&d[3]=='D'||d[3]=='C'&&b[3]=='D') cout<<0;
		else cout<<1;
	}
	else cout<<0;
}
