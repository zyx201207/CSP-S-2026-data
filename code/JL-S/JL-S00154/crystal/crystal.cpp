#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int o=1;
long long a[500001],t[500001];
void q(int l,int r){
	if(l>=r)return;
	int mid=(l+r)/2;
	q(l,mid);
	q(mid+1,r);
	cout<<'?';
	int i=l,f=mid+1;
	while(i<=mid&&f<=r){
		if(a[i]<=a[f]){
			t[o]=a[i];
			o=o+1;
			i=i+1;
		}
		else{
			t[o]=a[f];
			o=o+1;
			f=f+1;
		}
	}
	while(i<=mid){
		t[o]=a[i];
		o=o+1;
		i=i+1;
	}
	if(f<=r){
		while(f<=r){
			cout<<a[f]<<'/';
			t[o]=a[f];
			o=o+1;
			f=f+1;
		}
	}
	for(int f=1;f<=r;f++){
		a[f]=t[f];
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	q(1,n);
}
