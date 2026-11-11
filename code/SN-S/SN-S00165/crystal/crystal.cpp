#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+20;
int a[N],b[N];
int n,m;
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	bool flag=0;
	for(int i=2; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2; i<=n; i++) {
		b[i-1]=a[i]-a[i-1];
		if(i-1>=2) {
			if(b[i-1]!=b[i-2]) flag=1;
		}
	}

	if(flag==0) {
		int x=b[1];
		int sum=0;
		int i=1;
		while(i<n) {
			if(sum>m)break;
			sum+=i*x;
			i++;
		}
		cout<<--i;
		return 0;
	}
	int ans=-1;
	for(int i=1; i<=n; i++) {
		int cnt=0;
		int k=1,j=i;
		while(j<n) {
			cnt+=b[j++]*k;
			if(cnt>m) break;
			//cout<<k++<<' '<<cnt<<' ';
			k++;
		}
		//cout<<'\n';
		ans=max(ans,k);
	}
	cout<<ans;

	return 0;
}
