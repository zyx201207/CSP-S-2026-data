#include<bits/stdc++.h>
using namespace std;
int n,m;
int t[300005],a[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		t[a[i]]=i;
	}
	for(int i=1;i<=m;i++){
		if(t[i]) cout<<t[i]<<' ';
	}
	return 0;
}
