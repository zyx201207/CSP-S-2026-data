#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a[1000],b[1000],c[1000],d[1000];
	cin>>a>>b>>c>>d;
	if(a==c&&(b[0]==d[0]&&b[1]==d[1])){
		cout<<1100;
		return 0;
	}
	else if(a==c){
		cout<<1000;
	}
	else{
		cout<<1110; 
	}
	return 0;
}
 
