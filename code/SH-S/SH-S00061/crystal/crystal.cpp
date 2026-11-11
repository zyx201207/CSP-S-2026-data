#include<bits/stdc++.h>
#define lglg long long
using namespace std;

int n,ans;lglg m,a[500005];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie()->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	lglg sum=0;
	for(int i=1,j=1;i<=n;i++){
		sum+=(i-j)*(a[i]-a[i-1]);
		while(sum>m){sum-=a[i]-a[j];j++;}
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	return 0;
}
