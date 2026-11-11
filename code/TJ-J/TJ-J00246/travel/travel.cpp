#include<bits/stdc++.h>
using namespace std;
#define f(i,a,b)for(int i = a;i<=b;i++)
string n,m,a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>a>>m>>b;
	int h = 0,j = 0,d = 0;
	if(n == m){
		cout<<1;
		j = 1;
	}else cout<<0;
	if(a[0] == b[0]&&b[1] == a[1]&&j == 1){
		cout<<1;
		d = 1;
	}else cout<<0;
	if(((a[2] <='C'&&b[2]<='C')||(a[2]>'C'&&b[2]>'C'))&&j == 1&&d == 1){
		cout<<1;
		h = 1;
	}else cout<<0;
	if((a[2]+1 == b[2]||b[2]+1 == a[2])&&h == 1&&j == 1&&d == 1){
		cout<<1;
	}else cout<<0;
	return 0;
}
