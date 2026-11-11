#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[200005],n,m,ans[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int k=upper_bound(a+i,a+1+n,a[j])-lower_bound(a+i,a+1+n,a[j]);
			if(k%2)ans[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}

