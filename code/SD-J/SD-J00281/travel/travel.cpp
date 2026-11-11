#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string b,d,n,t;
	char k,v;
	int a,c;
	cin>>a>>b>>c>>d;
	cout<<(a==c);
	if(a==c){
	n=b.substr(0,2);
	t=d.substr(0,2);
	k=b[2];
	v=d[2];
	cout<<(n==t);
	if(n==t){
	cout<<((k<='C'and v<='C')or(k>='D'and v>='D'));
	if((k<='C'and v<='C')or(k>='D'and v>='D')){
		cout<<(k+1==v or v+1==k);
	} else{
		cout<<0;
	}}else{
		cout<<0<<0;
	}}else{
		cout<<0<<0<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
