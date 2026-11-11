#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,maxx=0;
int k[N]={},a[N]={};
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>k[i];
	}
	for(int i=1;i<=n;i++){
		int mexx=0;
		for(int j=1;j<=n;j++){
			a[j]=k[j];
			if(a[j]==k[i]){
				mexx++;
			}
		}
		int num=m;
		for(int j=1;j<=n;j++){
			if(a[j]<a[i]){
				int z=a[i]-a[j];
				if(num!=0 && z<=num){
					num=num-z;
					a[j]=a[i];
					mexx++;
				}
			}
		}
		if(mexx>maxx){
			maxx=mexx;
		}
	}
	cout<<maxx;
	return 0;
}
