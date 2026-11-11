#include <iostream>
using namespace std;
int a[1000000],m;
int q(int n,int siz,int zd,int w){
	int t=0,p;
	for(int i=n+1;i<=siz;i++){
		p=a[n]&q(i,siz,zd+1,w);
		cout<<p<<'/';
		if(t<p) t=p;
		if(t>w) w=t;
	}
	if(zd+1>=m || n==siz)return a[n];
	return w;
}
int main(){
	int n;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<q(1,n,0,0);
	return 0;
}
