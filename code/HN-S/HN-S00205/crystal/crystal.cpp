#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],b[N],y=0;
map<int,int>mp;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	int sum=0;
	for(int i=2;i<=n;i++){
		int j=i-1;
		if(a[i]>a[j]){
			sum+=(a[i]-a[j])*j;
			b[++y]=sum;
			mp[y]=i;
		}
		if(a[i]==a[j])mp[y]++;
	}
	int l=0,r=y+1,ans=0;
	while(l<=r){
		int mid=l+(r-l)/2;
		if(b[mid]<=m){
			ans=mid;
			l=mid+1;
		}else r=mid-1;
	}
	cout<<mp[ans];
	return 0;
}
