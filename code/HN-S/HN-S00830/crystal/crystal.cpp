#include <bits/stdc++.h>
using namespace std;
const int MAXN=500005;
long long a[MAXN];
long long diff[MAXN];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		diff[i]=a[i]-a[i-1];
	}
	sort(a+1,a+n+1);
	int maxn=1;
	for(int i=2;i<=n;i++){
		int j=i;
		int ans=1;
		while(diff[j]*(j-i+1)<=m){
			ans++;
			m-=diff[j]*(j-i+1);
			j++;
		}
		if(ans>maxn){
			maxn=ans;
		}
	}
	cout<<maxn;
	return 0;
 } 
