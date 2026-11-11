#include<bits/stdc++.h>
using namespace std;
const int N=500010;
long long a[N],sum[N],b[N];
long long int n,m,ans=1;
bool check(int x,int y){
	long long int ll=y-x+1,k=ll*a[y]-(sum[y]-sum[x-1]);
	if(k<=m)return 1;
	else return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
		long long int l=1,r=i-1;
		while(l<r){
			int mid=(l+r)>>1;
			if(check(mid,i)){
				r=mid;
			}
			else l=mid+1;
		}
		ans=max(i-r+1,ans);
	}
	cout<<ans;
	return 0;
}

