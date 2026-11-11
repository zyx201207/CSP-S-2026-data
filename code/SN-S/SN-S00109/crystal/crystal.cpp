#include<bits/stdc++.h>
using namespace std;

long long n,m,sum,ans;
long long a[500010];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	sum=(sum+m)/(n+1);
	for(int i=1;i<=n;i++){
		if(a[i]<=sum){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
