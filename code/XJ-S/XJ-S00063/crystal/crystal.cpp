#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m,a[N],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	if(n<=5000){
		for(int i=1;i<=n;i++){
			int s=0,cnt=1;
			for(int j=i-1;j>=1;j--){
				s+=a[i]-a[j];
				if(s>m) break;
				cnt++;
			}
			ans=max(ans,cnt);
		}
	}
	else{
		int d=a[2]-a[1];
		for(int i=1;i*d<=m&&i<n;i++) ans+=d*i;
	}
	cout<<ans;
	return 0;
}
