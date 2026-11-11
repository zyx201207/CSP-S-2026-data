#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+7;
int n,m;
long long a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long ans=0;
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++){
		long long j=i,cnt=0;
		while(cnt<=m&&j>=1){
			j--;
			cnt+=abs(a[i]-a[j]);
		}
		ans=max(ans,i-j);
	}
	cout<<ans;
}
