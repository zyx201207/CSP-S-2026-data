#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[1000010],sum[1000010];
bool cmp(int x,int y){
	return x<y;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int j=1;j<=n;j++){
		cin>>a[j];
	}
	sort(a+1,a+n+1,cmp);
	for(int j=1;j<=n;j++){
		sum[j]=sum[j-1]+a[j];
	}
	int maxn=INT_MIN;
	for(int j=1;j<=n;j++){
		int l=1,r=j,ans=0;
		while(l<r){
			
			int mid=(l+r)/2;
//			cout<<"#"<<mid<<" ";
			int x=(j-mid)*a[j]-m;
			int y=sum[j-1]-sum[mid-1];
			if(x<=y){
				ans=j-mid;
				r=mid;
			}else{
				l=mid+1;
			}
		}
		maxn=max(ans+1,maxn);
//		cout<<ans+1<<endl;
	}
	cout<<maxn;
	return 0;
}
