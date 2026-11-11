#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n,m;

struct node{
	int one,zero,v;
}a[200005];

int numzero(int p){
	int res=0;
	while(p){
		if(p%2==0){
			res++;
		}
		p/=2;
	}
	return res;
}

int numone(int p){
	int res=0;
	while(p){
		if(p%2){
			res++;
		}
		p/=2;
	}
	return res;
}

bool cmp(node a,node b){
	if(a.one==b.one){
		if(a.zero==b.zero){
			return a.v>b.v;
		}
		return a.zero>b.zero;
	}
	return a.one>b.one;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].v;
		a[i].one=numone(a[i].v);
		a[i].zero=numzero(a[i].v);
	}
	sort(a+1,a+n+1,cmp);
	int ans=a[1].v;
	for(int i=2;i<=m;i++){
		ans=ans&a[i].v;
	}
	cout<<ans;
	return 0;
}
