#include<bits/stdc++.h>
using namespace std;
int n,m,a[200007];
bool vA=1;
void solve2(){
	int j=1;
	for(int i=1;i<=m;i++){
		for(;j<=n&&a[j]==i;j++) ;
		cout<<j-1<<" ";
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	a[0]=-0x3f3f3f;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]) vA=0;
	}
	if(vA==1) solve2();
}
