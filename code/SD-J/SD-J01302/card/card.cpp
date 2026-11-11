#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[2000005];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
		int mx=0;
		for(int i=1;i<=n;i++){
			mx=max(mx,a[i]);
		}
		cout<<mx;
	
	return 0;
}
