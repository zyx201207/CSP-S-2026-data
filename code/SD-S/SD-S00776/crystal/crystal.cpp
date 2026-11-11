#include<bits/stdc++.h>
using namespace std;
int N;
typedef long long ll;
ll a[500010];
ll M;//O(n)
ll sum[500010];
void solve(){
	int ans=0;
	sort(a+1,a+N+1);
	for(int i=1;i<=N;i++){
		sum[i]=sum[i-1]+a[i];
		int l=1,r=i;
		while(l<r){
			int mid=(l+r+1)/2;
			if(sum[i]-sum[i-mid]+M>=a[i]*mid){
				l=mid;
			}
			else{
				r=mid-1;
			}
		}
		ans=max(l,ans);
	}  
	printf("%d\n",ans);
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&N,&M);
	for(int i=1;i<=N;i++){
		scanf("%lld",&a[i]);
	}
	solve();
	fclose(stdin);
	fclose(stdout); 
	return 0;
}

