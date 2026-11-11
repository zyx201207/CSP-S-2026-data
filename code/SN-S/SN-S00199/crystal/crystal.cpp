#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e6;
int a[N],n,m;
int pre[N];
signed main() {
	freopen ("crystal2.in","r",stdin);
	freopen ("crystal2.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int flag=a[(n%2==0)?n/2:n/2+1];
	for(int i=1;i<=n;i++){
		pre[i]=a[i]-flag;
	}
	int cnt=0,q=1;
	int minn=INT_MAX;
	for(int i=0;i<n;i++){
		int c=1;
		while(cnt<=m){
			if(pre[i+1]!=0){
				cnt+=abs(pre[i]);
			}else q=1;
			i++;
			c++;
		}
		minn=min(minn,c-q);
	}
	cout<<minn;
	return 0;
}
