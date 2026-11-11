#include<bits/stdc++.h>
using namespace std;
int n,cnt,l=1,r;
long long m,ans,a[500010],b[500010],s[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)cin >> a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++) b[i]=a[i]-a[i-1],s[i]=s[i-1]+b[i];
	for(r=2;r<=n;r++){
		ans+=b[r]*(r-l);
		while(1){
			if(ans<=m||l>=r) break;
			l++,ans-=s[r]-s[l-1];
 		}
		if(l==r) ans=0;
		cnt=max(cnt,r-l+1);
	}
	cout << cnt;
	return 0;
} 
