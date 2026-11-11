#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N];
long long n,ans,m;
long long sum;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int j=1;
	for(int i=1;i<=n;i++){
		while(sum<=m and j<=n){
			j++;
			sum+=(a[j]-a[j-1])*(j-i);
		}
		sum-=(a[j]-a[j-1])*(j-i);
		j--;
		ans=max(ans,(long long)j-i+1);
		sum-=a[j]-a[i];
	}cout<<ans;
	return 0;
}

