#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out" ,"w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		ans[a[i]]++;
		ans[a[n]]++;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i];
	}
	return 0;
}
