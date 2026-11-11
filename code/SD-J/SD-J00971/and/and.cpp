#include<bits/stdc++.h>
using namespace std; 
const int MAXN = 1e6 +5;
long long int a[MAXN];
long long int maxn=0; 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++)maxn=max(a[i] & a[j],maxn);
	}
	cout<<maxn;
	return 0;
}
