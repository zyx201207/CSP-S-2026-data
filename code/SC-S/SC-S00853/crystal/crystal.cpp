#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	a[0]=-0x3f3f3f3f;
	a[n+1]=0x3f3f3f3f;
	int ans=0;
	for(int i=1;i<=n;++i){
		int l=i-1,r=i+1,sum=0,cnt=0;
		while((sum<=m)&&(l>=1||r<=n)){
			int c1=a[r]-a[i];
			int c2=a[i]-a[l];
//			cout<<c1<<' '<<c2<<'\n';
			if(c1<c2){
				sum+=c1;
				cnt++;
				r++;
			}
			else{
				sum+=c2;
				cnt++;
				l--;
			}
		}
//		cout<<'\n';
		if(sum>m)
			cnt--;
		ans=max(ans,cnt+1);
	}
	cout<<ans<<'\n';
	return 0;
}
