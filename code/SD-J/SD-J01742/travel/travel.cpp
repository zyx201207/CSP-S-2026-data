#include<bits/stdc++.h>
using namespace std;
int a,b;
string c,d;
int main(){
    freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>c>>b>>d;
	bool pz=0;
	if(a==b) pz=1;
	else pz=0;
	if(pz) cout<<1;
	else cout<<0;
	
	bool p=0;
	string x={c[0]+c[1]},y={d[0]+d[1]};
	if(pz&&x==y) p=1;
	else p=0;
	if(p) cout<<1;
	else cout<<0;
	
	bool z=0;
	char c1=c[2],c2=d[2];
	int c11=int(c[2]),c22=int(d[2]);
	if(p&&max(c11,c22)-min(c11,c22)<=2&&!((c1=='C'&&c2=='D')||(c1=='D'&&c2=='C'))) z=1;
	else z=0;
	if(z) cout<<1;
	else cout<<0;
	
	
	if(z&&max(c11,c22)-min(c11,c22)==1) cout<<1;
	else cout<<0;
	return 0;
} 
