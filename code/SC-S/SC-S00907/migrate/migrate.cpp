#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int n;
unsigned long long d;
int a[2000005];
int ct=0;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	for(int i=1;i<=t;i++){
		ct=0;
		scanf("%lld%lld",&n,&d);
		for(int j=1;j<=n;j++)
			scanf("%lld",&a[j]);
		for(int j=1;j<n-2;j++){
			int k=j+2;
			if(a[j+1]-a[j]<=d&&a[k+1]-a[k]<=d&&a[k]-a[j]<=d&&a[k+1]-a[j+1]<=d&&k+1<=n&&a[k+1]-a[j]>d){
				ct++;
				//cout<<j<<'-'<<j+1<<'-'<<k+1<<'\n';
				//cout<<j<<'-'<<k<<'-'<<k+1<<'\n';
			}
					
		}
		cout<<ct<<'\n';
	}
	return 0;
}