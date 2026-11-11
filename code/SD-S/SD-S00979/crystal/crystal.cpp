#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int a[1000001],b[1000001],c,n,m,j,maxn;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)	cin>>a[i];
	j=1;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		c+=(i-j)*(a[i]-a[i-1]);
		while(i!=j&&c>m){
			j++;
			c-=(a[i]-a[j-1]);
		}
		if(i-j+1>maxn)	maxn=i-j+1;
	}
	cout<<maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

