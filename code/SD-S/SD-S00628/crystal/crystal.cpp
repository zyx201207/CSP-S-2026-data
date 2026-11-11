#include<bits/stdc++.h>
using namespace std;

#define F(i,s,e) for(int i=s;i<=e;i++)
const int N = 5e5+10;
using ll = long long;
int n;
long long m,a[N],s[N];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	F(i,1,n) cin>>a[i];
	sort(a+1,a+1+n);
	F(i,1,n) s[i]=s[i-1]+a[i];
	int ans = 1;
	F(i,1,n){
		int l=1,r=i;
		while(l<r){
			int mid=l+r>>1;
			if((i-mid+1)*a[i]-s[i]+s[mid-1]<=m) r=mid;
			else l=mid+1;
		}
//		cout<<l<<'\n';
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
} 
