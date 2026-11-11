#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
ll n,m;
ll a[N];
ll q[N],sum[N];
ll p[N],cnt[N],ma;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],cnt[i]=1;
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++) q[i]=a[i+1]-a[i],sum[i]=sum[i-1]+q[i];
	cnt[0]=1;p[1]=m;
	for(int i=1;i<n;i++){ 
		int j=cnt[i-1]+i-1;
		cnt[i]=cnt[i-1]-1;
		if(i==1) cnt[i]=0;
		while(j<n){
			if(p[i]>=q[j]*(cnt[i]+1)) p[i]-=q[j]*(cnt[i]+1),cnt[i]++;
			else break;
			j++;
		}
		p[i+1]=p[i]+sum[i+cnt[i]-1]-sum[i-1];
	}
	for(int i=1;i<=n;i++) ma=max(ma,cnt[i]+1);
	cout<<ma;
	return 0;
}