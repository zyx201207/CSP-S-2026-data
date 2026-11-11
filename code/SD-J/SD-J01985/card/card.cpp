#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int mn=1e9,mx=-1;
	for(int i=0;i<n;i++){
		cin>>a[i];
		mn=min(a[i],mn);
		mx=max(a[i],mx);
	} 
	cout<<m<<' '<<mn<<' '<<mx+1; 
	
	return 0;
}
