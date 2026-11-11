#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+10;
int n,m,a[maxn],c[maxn],pos=LONG_LONG_MAX,ans=0;
bool check(int x){
	int j=0,k=0,cnt=0,flag=0;
	pos=LONG_LONG_MAX;
	for(int i=1;i<=n-x+1;i++) pos=min(pos,a[i+x-1]-a[i]);
	for(int i=1;i<=n-x+1;i++){
		if(a[i+x-1]-a[i]==pos){
			j=i;k=i+x-1;
			break;
		}
	}
	cout<<k-j+1<<endl;
	for(int i=j;i<k;i++){
		cnt+=(a[k]-a[i]);
		if(cnt>m){
			flag=1;
			break;
		} 
	}
	if(flag==1) return false;
	else return true;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,r=n;
	while(l<r){
		int mid=(l+r)/2;
		if(check(mid)) l=mid+1;
		else r=mid-1;
	}
	cout<<l-1<<endl;
	return 0;
}