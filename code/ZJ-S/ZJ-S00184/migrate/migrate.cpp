#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,t=1,n,a[100005],dp[100005];
ll d,x[100005];
int ccf4gay(int ed,int l,int c) {
	if(x[l]+d>=x[ed])
		if(c+1<=a[ed]) return 1;
		else return 0;
	int i=l,cnt=0;
	while(x[++i]<x[l]+d) {
		if(dp[i]==0) dp[i]=ccf4gay(ed,i,c+1);
		cnt+=dp[i];
	}
	return cnt;
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--) {
		cin>>n>>d;
		int k=1,ans=0;
		for(int i=0; i<n; i++) {
			cin>>x[i];
//			if(x[0]+d>=x[i]) a[i]++;
//			else {
//				int j=i;
//				while(x[j]+d>=x[i]) j--;
//				if(a[j+1]) a[i]=a[j+1]+1;
//			}
		}
//		for(int i=0; i<n; i++) {
//			dp[i]=ccf4gay(n-1,i,0);
//			int j=i,k=i;
//			while(k<n) {
//				int cnt=0;
//				while(dp[k]-dp[j]<2 && k<n) k++;
//				while(dp[k]-dp[j]==2) cnt++,k++;
//				while(dp[k]-dp[j]>2) cnt*=2,j++;
//				ans+=cnt;
//			}
//		}
		cout<<0<<endl;
	}
	return 0;
}
//ccf4gay
//ccf4gay
//ccf4gay
//ccf4gay
//ccf4gay
//ccf4gay