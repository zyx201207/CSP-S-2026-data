#include <bits/stdc++.h>
using namespace std;
int n,ans=0,vis[500001],b=0;
long long m,s[500005],a[500001],p=1e18,cnt=0;
bool b1=0;
bool check(int h){
	return s[h]+cnt>m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++) if(a[i]-a[i-1]!=a[i-1]-a[i-2]) b1=1;
	if(!b1){
		for(int i=n-1;i>0;i--){
			if(cnt+a[n]-a[i]>m) break;
			cnt+=a[n]-a[i];
			ans++;
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++) s[i]=(a[i]-a[i-1])*(i-1);
	for(int i=1;i<=n;i++){
		s[i]+=s[i-1];
		s[i]%=p;
		if(s[i]<=s[i-1]) vis[i]=vis[i-1]+1;
	}
	for(int i=1;i<=n;i++){
		int l=i,r=n,h,k;
		while(l<=r){
			h=(l+r)/2;
			if(check(h)){
				r=h-1;
				k=h;
			}else{
				l=h+1;
			}
		}
		ans=max(ans,k-i);
		if(n-i+1<=ans) break;
		if(cnt-a[i]+cnt>=p) b++;
		if(cnt-a[i]+cnt<=-p) b--;
		cnt-=a[i]+cnt;
		cnt%=p;
	}
	cout<<ans;
	return 0;
}

