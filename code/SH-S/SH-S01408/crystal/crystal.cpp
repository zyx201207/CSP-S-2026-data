#include<bits/stdc++.h>
#define N 500009
#define int long long
using namespace std;
int n,m,a[N];
int mmax(int a,int b){return (a>b?a:b);}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int now=1,l=1,ans=0,cur=0;
	while(now<n){
		while(now<=n&&cur+(now-l+1)*(a[now+1]-a[now])<=m)cur+=(now-l+1)*(a[now+1]-a[now]),now++;
		if(now>=n){ans=mmax(ans,n-l);break;}
		ans=mmax(ans,now-l+1);
		if(l==now)l++,now++,cur=0;
		else cur-=a[now]-a[l],l++;
	}
	ans=mmax(ans,now-l+1);
	cout<<ans<<endl;
	return 0;
}

