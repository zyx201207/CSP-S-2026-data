#include<bits/stdc++.h>
using namespace std;
char x,y,c[200001];
long long int a,b,n,h,t,d,m[200001],ct;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	    cin>>m[i]>>c[i];
	a=m[1];
	b=m[n];
	x=c[1];
	y=c[n];
	h=1;
	t=n;
	d=min(a,b);
	for(int i=1;;i++){
		if(x!=y)ct+=d;
		a-=d;
		b-=d;
		if(a==0){
			h++;
			a=m[h];
			x=c[h];
		}
		if(b==0){
			t--;
			b=m[t];
			y=c[t];
		}
		d=min(a,b);
		if(h>=t)break;
	}
	cout<<ct;
	return 0;
}
