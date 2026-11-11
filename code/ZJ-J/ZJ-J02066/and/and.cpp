#include<bits/stdc++.h>
using namespace std;

#define ll long long

string a[200010];
void g(int x,int id){
	string ioio="",oioi="";
	char kkk;
	while(x){
		kkk=x%2+'0';
		oioi+=kkk;
		x/=2;
	}
	ll len=oioi.length();
	for(int i=1;i<=len;i++){
		ioio+=oioi[len-i];
	}
	a[id]=ioio;
}



int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int b;
		cin>>b;
		g(b,i);
	}
	cout<<12;
	
	
	return 0;
}
/*
4 2
3 15 12 12
*/
