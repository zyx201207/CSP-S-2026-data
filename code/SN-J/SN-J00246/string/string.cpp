#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct c{
	long long s;
	char c;
}; 
c a[200005];

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n, x=0, y;
	long long q;
	cin>>n;
	y=n-1;
	for(int i=0; i<n; i++){
		cin>>a[i].s>>a[i].c;
	}
	while(x<y){
		if(a[x].c!=a[y].c){
			q+=min(a[x].s, a[y].s);
		}
		if(a[x].s>a[y].s){
			a[x].s-=a[y].s;
			y--;
		}else if(a[x].s<a[y].s){
			a[y].s-=a[x].s;
			x++;
		}else{
			x++;
			y--;
		}
	}
	cout<<q;
	return 0;
}
