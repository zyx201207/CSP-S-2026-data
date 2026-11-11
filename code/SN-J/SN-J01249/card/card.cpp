#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[N],b,c,d;
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	for(int i = 1;i<=n;i++){
		que.push(a[i]);
	}
	cout<<b<<" "<<c<<" "<<d;
	return 0;
}

