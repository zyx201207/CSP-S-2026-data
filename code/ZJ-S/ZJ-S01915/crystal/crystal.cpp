#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],tail,head,sum,maxn;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		head++;
		sum+=(head-tail-1)*(a[head]-a[head-1]);
		while(sum>m){
			sum-=a[head]-a[tail];
			tail++;
		}
		maxn=max(maxn,head-tail);
	}
	cout<<maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}