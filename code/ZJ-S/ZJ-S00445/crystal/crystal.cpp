#include<bits\stdc++.h>
#define ll long long
using namespace std;
const int maxn=5e5+5;
int n;
ll m,a[maxn];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int left=1,right=1,ans=0;
	ll sum=0;
	while(right<=n){
		if(sum<=m){
			ans=max(ans,right-left+1);
			sum+=1ll*(a[right+1]-a[right])*(right-left+1);
			right++;
		}
		else{
			sum-=a[right]-a[left];
			left++;
		}
	}
	cout<<ans;
	return 0;
}