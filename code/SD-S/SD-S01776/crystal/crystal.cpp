#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=500010;
int n,m;
ll a[N];
ll f1[N];//前缀和
ll f2[N];//f2[i]表示将前i个数都变成a[i]的代价
ll f3[N];//f3[j]表示最多可以将k个数变成a[j]，用二分找到这个i:i+k-1=j,k=j-i+1
ll calc(int i,int j) { //计算将i~j的所有数字变成a[j]的代价
	return f2[j]-f2[i]-(a[j]-a[i])*(i-1);
}
int ans;
bool check(int i,int j) {
	return calc(i,j)<=m;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1; i<=n; i++)
		f1[i]=f1[i-1]+a[i];
	for(int i=1; i<=n; i++)
		f2[i]=i*a[i]-f1[i];

	if(f2[n]==m) {
		printf("%d",n);
		return 0;
	}
	if(f2[n]<m) {
		int k=(m-f2[n])/n;
		if(k*n+f2[n]==m)
			printf("%d",n);
		else
			printf("%d",n-1);
		return 0;
	}

	int startt=1;
	for(int i=1; i<=n; i++)
		if(f2[i]<=m) {
			ans=i;
			startt=i;
		} else
			break;
	startt++;
	for(int j=startt; j<=n; j++) { //对于每一个j，求出它最大的k，比较所有的k,求max
		int l=1,r=j;
//		cout<<j;
		while(l!=r) {
//			cout<<1;
			int mid=(l+r)>>1;
			if(check(mid,j)) {
				r=mid;
			} else {
				l=mid+1;
			}
		}
		int i=l;
		int k=j-i+1;
//		cout<<k<<" ";
		ans=max(ans,k);
	}

	printf("%d",ans);








//	for(int i=1; i<=n; i++)
//		cout<<a[i]<<" ";
//	cout<<"\n";
//	for(int i=1; i<=n; i++)
//		cout<<f1[i]<<" ";
//	cout<<"\n";
//	for(int i=1; i<=n; i++)
//		cout<<f2[i]<<" ";
//	cout<<"\n";
//	while(1) {
//		int x;
//		int y;
//		cin>>x>>y;
//		cout<<calc(x,y)<<"\n";
//	}
	return 0;
}
