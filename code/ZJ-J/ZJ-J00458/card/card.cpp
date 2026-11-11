#include<bits/stdc++.h>
using namespace std;
//this is wrong.
int a[500001],now[500001],t[500001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;++i)cin>>a[i];
	for(int st=0;st<n;++st){
		int *app[n]={};
		int *p=now;
		for(int i=st;i<n;++i){
			if(app[a[i]])p=app[a[i]]+1;
			else app[a[i]]=p,*p++=a[i];
		}
		for(int *d=now;d<p;++d){
			++t[*d];
		}
	}
	for(int i=1;i<=m;++i)cout<<t[i]<<' ';
}