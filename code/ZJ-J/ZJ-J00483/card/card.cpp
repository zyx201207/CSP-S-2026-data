#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+10;
unsigned int n,m;
unsigned int V[MAXN];
unsigned int last[MAXN];
unsigned int ans[MAXN];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(unsigned int i=0; i<n; i++) {
		cin>>V[i];
		last[V[i]]=i;
	}
	for(unsigned int i=0; i<n; i++) {
		for(unsigned int j=i; j<n; j++) {
			ans[V[j]]++;
			j=last[V[j]];
		}
	}
	for(unsigned int k=1; k<=m; k++) {
		cout<<ans[k]<<" ";
	}
	return 0;
}