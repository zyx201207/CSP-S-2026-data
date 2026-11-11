#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freout("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int maxn=0;
	for(int i=1;i<=n;i++){
		maxn==(n[i]&&n[i+1]);
		if(n[i]&&n[i+2]>n[i]&&n[i+1]){
			maxn==n[i]&&n[i+1];
		}
	}
	cout<<maxn;
	return 0;
}