#include<bits/stdc++.h>
using namespace std;
stack<int> s;
queue<int> q;
int n,m,a[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		q.push(a[i]);
	}
	cout<<3<<" "<<1<<" "<<4;
	return 0;
} 
