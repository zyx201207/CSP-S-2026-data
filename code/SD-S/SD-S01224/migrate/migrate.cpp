#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T;
int n,d,a[2000005];
int b[2000005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		a[0]=-5e18;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(c==11||c==12){
			if(n==1){
				cout<<0<<'\n';
				continue;
			}
			int qwq=a[2]-a[1];
			int l=0,r=2e18,mid,awa=0;
			while(l<=r){
				mid=(l+r)/2;
				if(mid*qwq<=d)awa=mid,l=mid+1;
				else r=mid-1;
			}
			if(awa<=1)cout<<0<<'\n';
			else{
				int len=2*awa-1;
				cout<<max(0ll,n-len)<<'\n';
			}
			continue;
		}
		if(c==13||c==14){
			int duiye=0,ans=0;
			for(int i=1;i<=n;i++){
				if(a[i]-d<=a[1]&&a[i]+d>=a[n])duiye=i;
			}
			for(int i=1;i<duiye-1;i++){
				if(a[i]+d>=a[duiye+1])continue;
				int L=duiye-1,R=0;
				int l=duiye+1,r=n,mid;
				while(l<=r){
					mid=(l+r)/2;
					if(a[mid]<=a[duiye-1]+d)R=mid,l=mid+1;
					else r=mid-1;
				}
				l=duiye+1,r=n;
				while(l<=r){
					mid=(l+r)/2;
					if(a[mid]>a[duiye-2]+d)L=mid,r=mid-1;
					else l=mid+1;
				}
				if(R)ans+=R-L+1;
			}
			for(int i=1;i<duiye;i++){
				if(a[i]+d>=a[duiye+2])continue;
				int k=duiye+1;
				int l=duiye+2,r=n,mid;
				while(l<=r){
					mid=(l+r)/2;
					if(a[mid]<=a[duiye-1]+d)k=mid,l=mid+1;
					else r=mid-1;
				}
				ans+=n-k;
			}
			cout<<ans<<'\n';
			continue;
		}
		int lst,ans=0;
		for(int i=1;i<=n;i++){
			lst=0;
			for(int j=i;j<=n;j++)b[j]=0;
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[j-1]>d)break;
				if(lst-2>=i&&a[j]-a[lst-2]<=d)b[j]=2;
				else if(lst-1>=i&&a[j]-a[lst-1]<=d){
					if(b[lst-1]||b[lst])b[j]=2;
					else b[j]=1;
				}
				else if(lst>=i&&a[j]-a[lst]<=d)b[j]=b[lst];
				else if(j-3>=i&&a[j]-a[j-3]<=d)b[j]=2,lst=j-1;
				else if(j-2>=i&&a[j]-a[j-2]<=d){
					if(b[j-2]||b[j-1])b[j]=2;
					else b[j]=1;
					lst=j-1;
				}
				else{
					b[j]=b[j-1];
					lst=j-1;
				}
				if(b[j]==1)ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 1
10 3
0 3 6 7 8 9 10 11 14 17

13 1
6 3
1 2 3 4 5 6

13 1
7 8
1 3 5 6 9 12 14 17
*/
