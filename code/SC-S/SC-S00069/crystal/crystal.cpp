#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5e5;
int n,m,a[MAXN];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans=1;
	for(int len=2;len<=n;len++){
		for(int i=1;i+len-1<=n;i++){
			int j=i+len-1;
			int sum=0;
			int maxx=*max_element(a+i+1,a+j+1);
			for(int k=i;k<=j;k++){
				sum+=a[k];
			}
			if((sum+m)%len==0&&(sum+m)/len>=maxx){
				ans=len;
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}