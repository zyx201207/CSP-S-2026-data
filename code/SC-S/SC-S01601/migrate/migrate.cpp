#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
int c,T;
int n,d;
int a[N];
int ans[N];
void solve(){
	memset(ans,0,sizeof ans);
	cin>>n>>d;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);a[n+1]=2e18;
	for(int i=n-3;i>=1;i--){
		int now=i; 
//		while(now<=n){
			int mx=now,fl=0;//Ò»´ÎÌøÂú 
			for(;mx<=n;mx++){
				if(a[mx+1]-a[now]<=d)continue;
				else break;
			}
//			if(i==1)cout<<mx<<'\n';
			int mx1=mx-1,mx2=mx-2;//Ò»´Î´ÎÂú 
			int mm=mx,mm1=mx1,mm2=mx2;
			for(;mm<=n;mm++){
				if(a[mm+1]-a[mx]<=d)continue;
				else break;
			}
			for(;mm1<=n;mm1++){
				if(a[mm1+1]-a[mx1]<=d)continue;
				else break;
			}
			for(;mm2<=n;mm2++){
				if(a[mm2+1]-a[mx2]<=d)continue;
				else break;
			}//¶þÌø£¬ÔÚ2-3¿ÉÒÔ£¬1-2Ò»¸ö£º¼ÌÐø£¬Á½¸ö£ºÌøÒ»´Î½áÊø£¬¶à¸ö£º½áÊø 
//			if(i==1)cout<<mm1<<' '<<mm2<<'\n';
			ans[i]+=mm1-mm2;
			for(int j=mm1+1;j<=mm;j++)ans[i]+=ans[j];
//			if(mm-mm1>2)break;
//			else if(mm-mm1==2){
//				int mn=mm,mn1=mm-1;
//				for(;mn<=n;mn++){
//					if(a[mn]-a[mm]<=d)continue;
//					else break;
//				}
//				for(;mn1<=n;mn1++){
//					if(a[mn1]-a[mm1]<=d)continue;
//					else break;
//				}
//				ans+=
//				break;
//			} 	
//			else now=mm;
//		}
	}
	int res=0;
	for(int i=1;i<=n;i++){
		res+=ans[i];
//		cout<<ans[i]<<' ';	
	}
	cout<<res<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		solve();
	}
	return 0;
}