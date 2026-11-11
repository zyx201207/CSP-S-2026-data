#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m,a[N];
int cnt[5];
int countm(int x){
	int res=0;
	while(x){
		++res;
		x&=(x-1);
	}
	return res;
}
bool cmp(int a,int b){
	return a>b;
}
int maxxnum=-1e18;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxxnum=max(maxxnum,a[i]);
	}

//	pw[0]=1ll;
//	for(int i=1;i<=30;i++){
//		pw[i]=pw[i-1]*2ll;
//	}
//	cout<<(0&235674);
	if(m==1){
		int ans=-1e18;
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}
	if(n<=2000&&m==2){
		int ans=-1e18;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,(a[i]&a[j]));
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans=(ans&a[i]);
		}
		cout<<ans;
		return 0;
	}

	if(n<=20){
		int maxx=-1e18;
		for(int mask=0;mask<(1<<n);mask++){
			int ans=0;
			if(countm(mask)!=m) continue;
			for(int i=1;i<=n;i++){
				if(mask&(1<<(i-1))){
					if(ans==0){
						ans=a[i];
					}
					else ans=(ans&a[i]);
				}
			}
			maxx=max(maxx,ans);
		}
		cout<<maxx;
		return 0;
	}
	if(maxxnum<=4){
		int ans=0;
		int sum=a[1];
		for(int i=1;i<=n;i++){
			++cnt[a[i]];
		}
		for(int i=2;i<=n;i++){
			sum=(sum&a[i]);
		}
		ans=sum;
		for(int i=0;i<=4;i++){
			if(cnt[i]>=m) ans=max(ans,i);
		}
		for(int i=0;i<=4;i++){
			for(int j=i+1;j<=4;j++){
				if(cnt[i]+cnt[j]>=m){
					ans=max(ans,(i&j));
				}
			}
		}
		for(int i=0;i<=4;i++){
			for(int j=i+1;j<=4;j++){
				for(int k=j+1;k<=4;k++){
					if(cnt[i]+cnt[j]+cnt[k]>=m){
						ans=max(ans,(i&j&k));
					}
				}
			}
		}
		for(int i=0;i<=4;i++){
			for(int j=i+1;j<=4;j++){
				for(int k=j+1;k<=4;k++){
					for(int h=k+1;h<=4;h++){
						if(cnt[i]+cnt[j]+cnt[k]+cnt[h]>=m){
							ans=max(ans,(i&j&k&h));
						}
					}
				}
			}
		} 
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	int res=a[1];
	for(int i=2;i<m;i++){
		res=(res&a[i]);
	}
	cout<<res;
	return 0;
}

