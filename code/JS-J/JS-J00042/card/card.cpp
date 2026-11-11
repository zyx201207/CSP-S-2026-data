#include<bits/stdc++.h>
using namespace std;
const int N=50005;
int ct[N];
int a[N];
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[j-1]!=a[j]){
				i++;
			}
		}
		ct[i]++;
	}
	for(int i=1;i<=m;i++) cout<<ct[i]<<' ';
	return 0;
}
