#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],d[500005],f,nw;
bool sp=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		d[a[i]]++; 
	}
	for(int i=1;i<=m;i++){
		cout<<d[i]+f<<' ';
		f=f+d[i];
	}
	return 0;
} 
