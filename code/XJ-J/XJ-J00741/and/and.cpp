#include<bits/stdc++.h>
using namespace std;
int n,m;
int na[10000000];
int main(){
	freopen("and.in","r",stdin);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>na[i];
	}
	int ma[m+1];
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			ma[i]=max(na[j],na[j+1]);
	}}
	freopen("and.out","w",stdout);
	cout<<ma[m];
	reten 0;
}