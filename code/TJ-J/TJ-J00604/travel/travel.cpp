#include <bits/stdc++.h>
using namespace std;
struct zuowei{
	int c;
	char a,b,n;
};
int main(){
	freopen ("travel.in","r",stdin);
	freopen ("travel.out","w",stdout);
	zuowei x,y;
	cin>>x.c>>x.a>>x.b>>x.n>>y.c>>y.a>>y.b>>y.n;
	if (x.c==y.c){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	if (x.a==y.a && x.b==y.b){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	if (x.n-'A'+y.n-'A'!=5 || x.n=='F' || y.n=='F'){
		cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
	if (abs(x.n-y.n)==2 && x.n!='A' && y.n!='A') {
		cout<<1;
		
	}
	else if (abs(x.n-y.n)==1){
		cout<<1;
	}
	
	else{
		cout<<0;
	}
	return 0;
} 
