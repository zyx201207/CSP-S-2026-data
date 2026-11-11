#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ct[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	if(n>=5){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=2;i<=n+1;i++){
			if(a[i]!=a[i-1]){
				ct[a[i-1]]=i-1;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<ct[i]<<" ";
		}
	}
}
