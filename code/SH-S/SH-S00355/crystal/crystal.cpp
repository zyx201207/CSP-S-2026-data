#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005],sum[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	a[0]=0,sum[0]=0;
	int f=0;
	for(int i=1;i<=n;i++){
		sum[i]=a[i]-a[i-1];
	}
	for(int i=2;i<=n;i++){
		if(sum[i]!=sum[i-1]){
			f=1;
			break;
		}
	}
	if(!f){
		int an=0;
		for(int i=1;i<=n;i++){
			an+=a[i];
			if(an>m){
				cout<<i-1;
				return 0;
			}
		}
		cout<<n;
		return 0; 
	}
	int maxm=0,mid=0,l=0,r=0,pow=0;
	for(int i=1;i<=n;i++){
		maxm=max(maxm,sum[i]);
	}
	for(int i=1;i<=n;i++){
		if(sum[i]==maxm){
			mid=i;
			break;
		}
	}
	int flag=0;
	for(int i=1;i<=mid-1;i++){
		pow=pow+sum[i];
		if(pow>m){
			r=i;
			flag=1;
			break;
		}
	}
	if(!flag){
		r=mid-1;
	}
	pow=0;
	for(int i=mid;i<=n;i++){
		pow=pow+a[n]-a[i];
		if(pow>m){
			l=i-mid+1;
			flag=1;
			break;
		}
	}
	if(!flag){
		l=n-mid+1;
	}
	cout<<max(r,l);
	return 0;
}
