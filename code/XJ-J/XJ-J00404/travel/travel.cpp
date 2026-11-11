#include<bits/stdc++.h>
using namespace std;
struct id{
	long long c;
	char s;
};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	id a;
	id b;
	cin>>a.c>>a.s>>b.c>>b.s;
	if(a.c==b.c){
		cout<<'1100';
	} 
	else cout<<'0000';
	return 0;
}