#include<bits/stdc++.h>
using namespace std;
int a[100010];

int main(){
	freopen(card.in,"r",stdin);
	freopen(card.out,"w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
