#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	bool p=1;
	for(int i=1;i<n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]) p=0;
	}
	if(p){
		for(int i=1;i<=n;i++){
			if(a[i]!=a[i+1]) cout<<i<<" ";
		}
		cout<<n;
	}
	return 0;
}
