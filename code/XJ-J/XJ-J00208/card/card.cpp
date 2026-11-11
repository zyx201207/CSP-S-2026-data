#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int a[maxn];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m,ans=0;
	cin>>n>>m;
	for (long long i=1;i<=n;i++){
		cin>>a[i];
	}	
	for (long long i=1;i<=m;i++){
		ans++;
	}
	for (long long i=1;i<=ans;i++){
		cout<<1;
	}

	return 0;
}
