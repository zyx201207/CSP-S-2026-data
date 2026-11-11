#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005];
int sum,xsum;
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;for(int i=1;i<=n;i++)cin>>a[i];
	if(m==n)for(int i=1;i<=n;i++)xsum=xsum and a[i];
	else if(m==1){
		int xsum=INT_MIN;
		for(int i=1;i<=n;i++)xsum=max(xsum,a[i]);
	}else if(m==2){
		int xsum=INT_MIN;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				int q=a[i] and a[j];
				xsum=max(xsum,q);
			}
		}
	}cout<<xsum;
	return 0;
}//按位与是啥?是and还是&?好难猜呀!
