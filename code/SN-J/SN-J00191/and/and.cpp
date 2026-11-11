#include<bits/stdc++.h>
using namespace std;

long long n,m,ans,sum,cnt;
long long a[200010];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-m+1;i++){
		sum=a[i];
		for(int j=i+1;j<=i+m-1;j++){
			sum&=a[j];
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}
