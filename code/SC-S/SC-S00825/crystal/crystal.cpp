#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
int n;
long long m,a[MAXN],s[MAXN];
int ans=0;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int l,r,mid,res;
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
		l=0,r=i-1;
		res=0;
		while(l<=r){
			mid=(l+r)/2;
//			printf("(%d,%d,%d)",l,r,mid);
			if(a[i]*mid-s[i-1]+s[i-1-mid]<=m){
				l=mid+1;
				res=mid;
			}
			else r=mid-1;
		}
//		cout<<res<<"\n";
		ans=max(ans,res+1);
	}
	cout<<ans;
	return 0;
}