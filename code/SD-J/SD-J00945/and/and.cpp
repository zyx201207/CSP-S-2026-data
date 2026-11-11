//递归枚举+特殊点6*5tps O(n^m)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=2e5+10;
int n,m,a[N],ans;
int b[N];
void f(int k,int l,int r) {
	if (k==m+1) {
		int answ=a[b[1]];
		for (int i=1;i<=m;i++) {
//			cout<<b[i]<<" ";
			answ&=a[b[i]];
		}
//		cout<<": "<<answ<<endl;
		ans=max(ans,answ);
		return ;
	}
	for (int i=l;i<=r;i++) {
		b[k]=i;
		f(k+1,i+1,r);
	}
}
signed main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for (int i=1;i<=n;i++) {
		scanf("%lld",&a[i]);
	}
	if (n==m) {
		ans=a[1];
		for (int i=1;i<=n;i++) {
			ans&=a[i];
		}
		cout<<ans<<endl;
		return 0;
	}
	f(1,1,n);
	cout<<ans<<endl;
	return 0;
}



//优化解
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//const int N=2e5+10;
//int n,m,ans,sum[40],t=30;
//vector <int> a,b;
//bool bi[N][40];
//signed main() {
////	freopen("and3.in","r",stdin);
////	freopen("and.out","w",stdout);
//	scanf("%lld%lld",&n,&m);
//	for (int i=1,x;i<=n;i++) {
//		scanf("%lld",&x);
//		a.push_back(x);
//	}
//	if (n==m) {
//		ans=a[0];
//		for (int i=0;i<n;i++) {
//			ans&=a[i];
//		}
//		printf("%lld\n",ans);
//		return 0;
//	}
//	b=a;
//	a=vector <int> (0);
//	while (a!=b||b.size()!=m) {
//		a=b;
//		b=vector <int> (0);
//		memset(bi,0,sizeof(bi));
//		memset(sum,0,sizeof(sum));
//		for (int i=0;i<a.size();i++) {
//			int temp=a[i],k=0;
//			while (temp) {
//				bi[i][++k]=temp%2;
//				temp/=2;
//			}
////			for (int j=1;j<=k;j++) {
////				cout<<bi[i][j];
////			}
////			cout<<endl;
//		}
//		for (int i=1;i<=t;i++) {
//			for (int j=0;j<n;j++) {
//				sum[i]+=bi[j][i];
//			}
//		}
//		cout<<"-----";
//		for (int i=t;i>=1;i--) {
//			cout<<sum[i]<<" ";
//		}
//		cout<<endl;
//		for (int i=t-1;i>=0;i++) {
//			if (sum[i]>=m) {
//				t=i;
//				for (int j=0;j<a.size();j++) {
//					if (bi[j][t]) {
//						b.push_back(a[j]);
//					}
//				}
//				break;
//			}
//		}
//	}
//	a=b;
//	cout<<a.size()<<endl;
//	ans=a[0];
//	for (int i=0;i<a.size();i++) {
//		ans&=a[i];
//		printf("%lld\n",a[i]);
//	}
//	printf("%lld\n",ans);
//	return 0;
//}
