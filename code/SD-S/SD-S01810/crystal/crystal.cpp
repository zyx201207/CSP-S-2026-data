#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans=1,sum,j=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long t=1;
	for(int i=2;i<=n;i++){
		sum+=(i-j)*(a[i]-a[i-1]);
		if(sum<=m){
			t++;
		}
		while(sum>m){
			sum-=a[i]-a[j];
			j++,t--;
		}
		ans=max(ans,t);
	}
	cout<<ans;
	return 0;
} 
