#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200005],n,sum,ans;
char c[200005],d[10000005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++)
		    d[j+sum]=c[i];
		sum+=a[i];
	}
	for(int i=1;i<=sum/2;i++)
		if(d[i]!=d[sum+1-i])ans++;
	cout<<ans;
}