#include<bits/stdc++.h>
using namespace std;
struct node{
	int id,p;
	char x;
}a,b;
inline int get(char c){
	return c-'0';
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	char c[100];
	for(int i=1;i<=4;i++){
		cin>>c;
		if(i==1) a.id=get(c[0])*10+get(c[1]);
		else if(i==3) b.id=get(c[0])*10+get(c[1]);
		else if(i==2){
			a.p=get(c[0])*10+get(c[1]);
			a.x=c[2];
		}
		else{
			b.p=get(c[0])*10+get(c[1]);
			b.x=c[2];
		}
	}
	if(a.x=='D') a.x='E';
	if(b.x=='D') b.x='E';
	cout<<(a.id==b.id);
	cout<<(a.p==b.p&&a.id==b.id);
	cout<<(a.p==b.p&&a.id==b.id&&a.x<='C'&&b.x<='C');
	cout<<(a.p==b.p&&a.id==b.id&&abs(a.x-b.x)==1);
	return 0;
} 
