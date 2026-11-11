#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a=0,b=0,c=0,d=0;
	string x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;
	int x=(x1[0]-'0')*10+(x1[1]-'0');
	int y=(x2[0]-'0')*10+(x2[1]-'0');
	int l=(y1[0]-'0')*10+(y1[1]-'0');
	int r=(y2[0]-'0')*10+(y2[1]-'0');
	char u=y1[2],v=y2[2];
	if(x==y){
		a=1;
		if(l==r){
			b=1;
			if((u<='C'&&v<='C'||u>='D'&&v>='D')){
				c=1;
				if(u=='A'&&v=='B') d=1;
				else if(u=='B'&&v=='C') d=1;
				else if(u=='D'&&v=='F') d=1;
			} 
		}
	}
	cout<<a<<b<<c<<d<<endl;
	return 0;
}
