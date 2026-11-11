#include <bits/stdc++.h>
using namespace std;
const int N=500005;
long long n,m,a[N],ans,sum[N]; 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i-ans;j>=1;j--){
			if(((a[i]*(i-j+1))-(sum[i]-sum[j-1]))>m) break;
			ans++;
		}
	}cout<<ans;
	return 0;
} 
