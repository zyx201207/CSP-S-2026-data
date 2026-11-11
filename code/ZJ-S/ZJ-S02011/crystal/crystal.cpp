#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],b[500005][2],cnt=1,ans=0;
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	b[cnt][0]=a[1];
	b[cnt][1]=1;
	for(ll i=2;i<=n;i++){
		if(a[i]==a[i-1]){
			b[cnt][1]++;
		}else{
			cnt++;
			b[cnt][0]=a[i];
			b[cnt][1]=1;
		}
	}
	ll r=2,sum=0,sum2=b[1][1],d=0;
	for(ll i=1;i<=cnt;i++){
		while(r<=cnt){
			ll bj=b[i][0]-b[r][0];
			if(bj*b[r][1]+sum<=m){
				sum2+=b[r][1];
				sum+=(b[r][1]*bj);
				r++;
				d=0;
			}else{
				d=(m-sum)/bj;
				sum2+=d;
				break;
			}
		}
		ans=max(ans,sum2);
		sum2=sum2-d-b[i][1];
		sum=sum-sum2*(b[i][0]-b[i+1][0]);
	}
	cout<<ans<<"\n";
	return 0;
}