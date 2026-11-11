#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int a[500010],n,m,mid;
bool chk(int mid){
	int sum=0;
	for(int i=1;i<=mid;i++)
		sum+=a[mid]-a[i];
	return sum<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,r=n,mid,ans=1;
	while(l<r){
		mid=(l+r)/2;
		if(chk(mid)){
			ans=mid;
			l=mid+1;
		}
		else
			r=mid;
	}
	cout<<ans;
	return 0;
} //75pts 

