#include<bits/stdc++.h>
#define IOSO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define endl '\n'
#define QwQ return 0;
#define int long long
using namespace std;
const int N=5e5+10;
int pre[N],a[N];
signed main(){
	IOSO;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	int maxx=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i,ans=0;
		while(l<=r){
			int mid=(l+r)/2;
			int jl=i-mid+1;
			int cha=jl*a[i];
			int sum=pre[i]-pre[mid-1];
			if(cha-sum<=m){
				r=mid-1;
				ans=mid;
			}else{
				l=mid+1;
			}
		}
		maxx=max(maxx,i-ans+1);
	}
	cout<<maxx<<endl;
	QwQ;
}