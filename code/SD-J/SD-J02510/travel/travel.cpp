#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>
#include<stack>
#include<queue>
#include<map>
using namespace std;


int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,c;
	string b,d;
	cin>>a>>b>>c>>d;
	int e=(b[0]-'0'*10)+b[1]-'0';
	int f=(d[0]-'0'*10)+d[1]-'0';
	char g=b[2],h=d[2];
	int i,j,k,l;
	if(g=='A'){
		i=0;
		j=1;
	}
    if(g=='B'){
		i=0;
		j=2;
	}
	if (g=='C'){
		i=0;
		j=3;
	}
	if (g=='D'){
		i=1;
		g=5;
	}
	if (g=='F'){
		i=1;
		g=6;
	}
	if(h=='A'){
		k=0;
		l=1;
	}
    if(h=='B'){
		k=0;
		l=2;
	}
	if (h=='C'){
		k=0;
		l=3;
	}
	if (h=='D'){
		k=1;
		l=5;
	}
	if (h=='F'){
		k=1;
		l=6;
	}
	if (a==c) cout<<1;
	else cout<<0;
	if (a==c&&e==f) cout<<1;
	else cout<<0;
	if (a==c&&e==f&&i==k) cout<<1;
	else cout<<0;
	if (a==c&&e==f&&i==k&&abs(l-j)==1) cout<<1;
	else cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
