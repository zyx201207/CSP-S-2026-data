#include <bits/stdc++.h>
using namespace std;
long long a[100005];
int maxx=-1,ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int i=1,j=i+m;i<=n,j<=n;i++,j++){
		ans=a[i];
		for (int k=i+1;k<=j;k++){
			ans=(ans&a[k]);
		}		
		maxx=max(maxx,ans);
	}
	cout<<maxx;
}