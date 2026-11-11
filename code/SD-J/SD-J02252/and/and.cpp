#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int k,v[200005],maxn=0;
	for(int i=1;i<=n;i++){
		cin>>v[i];
	}
	sort(v+1,v+n+1,greater<int>());
	k=v[1];
	for(int i=2;i<=m;i++){
		k&=v[i];
	}
	maxn=k;
	for(int i=m+1;i<=n;i++){
		k|=v[i-m];
		k&=v[i];
		maxn=max(maxn,k);
	}
	cout<<maxn<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
