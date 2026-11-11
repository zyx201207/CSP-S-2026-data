#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005];
int ans,ans1,maxx=0xcfcfcfcfcfcfcfcf,minn=0x3f3f3f3f3f3f3f3f;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
		minn=min(minn,a[i]);
	}
	for(int x=minn;x<=maxx;x++){
		int h=m;
		ans1=0;
		for(int i=1;i<=n;i++){
			if((x<0 && a[i]>=0) || (x>=0 && a[i]<0)){
				if((abs(x)+abs(a[i]))<=h){
					if(x<a[i]) continue;
					ans1++;
					h-=(abs(x)+abs(a[i]));
				}
			}
			else{
				if((abs(x)-abs(a[i]))<=h){
					if(x<a[i]) continue;
					ans1++;
					h-=(abs(x)-abs(a[i]));
				}
			}
		}
		ans=max(ans,ans1);
	}
	cout<<ans;
	return 0;
}

