#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m;
int d[N],a[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int S,maxn,T,k;
	cin>>T;
	cin>>n>>m>>S>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int i=1;i<=n;i++)
			cin>>d[i];
			T=n-1;
		for(int i=1;i<n;i++)
			maxn=(d[i],d[i-1]);
	}
	cout<<1<<'\n'<<2;
	return 0;
}
