#include<bits/stdc++.h>
using namespace std;
int n,nn=1,m,a[500005],q[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		q[a[i]]++;
	}
	for(int i=1;i<=m;i++){
		cout<<q[i]<<" ";
	}
	return 0;
}

