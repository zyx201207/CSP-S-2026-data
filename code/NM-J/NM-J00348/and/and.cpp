#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[100010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)cin >> a[i];
	for(int i=1;i<=n;i++)ans=max(ans,ans|a[i]);
	return 0;
}
