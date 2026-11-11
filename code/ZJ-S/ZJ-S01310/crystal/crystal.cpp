#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
#define int long long
int n,m,a[N],ans,sum;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int x=a[1];
	for(int i=1,j=1;i<=n;i++){
		sum+=(a[i]-x)*(i-j);
		x=a[i];
		while(sum>m){
			sum=sum-(x-a[j]);
			j++;
		}
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	return 0;
}
