#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define y1 yellow1
#define ull unsigned long long
#define rank jkflsfasf
#define time fjklsaflsdfj
inline ll rd(){
	ll k=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		k=k*10+c-'0';
		c=getchar();
	}
	return k*f;
}
int c1,c2,a1,a2;
char b1,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>a1>>b1>>c2>>a2>>b2;
	if(c1==c2){
		cout<<1;
		if(a1==a2){
			cout<<1;
			if((b1<='C'&&b2<='C')||(b1>'C'&&b2>'C')){
				cout<<1;
				if(b1>'C'||abs(b1-b2)==1){
					cout<<1;
				}
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
