#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+8;
int n,m;
int a1,a2;
char b1,b2;
int c1,c2,c3,c4;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>a1>>b1>>m>>a2>>b2;
	if(n==m){
		c1=1;
		if(a1==a2){
			c2=1;
			if((b1=='A'||b1=='B'||b1=='C')&&b2!='D'&&b2!='F'){
				c3=1;
				if(b1=='A'&&b2=='B'){
					c4=1;
				}else if(b1=='B'&&(b2=='A'||b2=='C')){
					c4=1;
				}else if(b1=='C'&&b2=='B'){
					c4=1;
				}
			}else if(b1=='D'&&b2=='F'){
				c3=1;
				c4=1;
			}else if(b1=='F'&&b2=='D'){
				c3=1;
				c4=1;
			}
		}
	}
	cout<<c1<<c2<<c3<<c4;
	return 0;
}

