#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[20000000];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int maxn=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<=n;j++){
			maxn=(maxn,i and j);
		}
	}
	cout<<maxn;
	return 0;
}
