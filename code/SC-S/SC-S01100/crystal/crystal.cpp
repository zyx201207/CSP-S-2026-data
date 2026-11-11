#include<bits/stdc++.h>
using namespace std;
long long a[500005],pre[500005],q[500005];
long long n,m;
bool check(int mid){
	int h=1,t=0;
	for(int i=1;i<=n;i++){
		while(h<=t&&a[i]>=a[q[t]])t--;
		q[++t]=i;
		while(h<=t&&q[h]+mid<=i)h++;
		if(i>=mid&&a[q[h]]*mid-(pre[i]-pre[i-mid])<=m)return 1;
	}return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}int l=1,r=n,ans=0;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else r=mid-1;
	}cout<<ans;
} 