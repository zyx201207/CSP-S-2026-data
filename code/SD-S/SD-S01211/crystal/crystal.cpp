#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int a[N],s,n,l,m,ans; 
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);int l=1;
	for(int i=1;i<=n;i++){
		while(a[i]*(i-l)-s>m){
			s-=a[l];
			l++;
		}
		ans=max(ans,i-l+1);
		s+=a[i];
	}
	cout<<ans;
	return 0;
} 
