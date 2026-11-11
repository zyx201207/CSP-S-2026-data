#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt,maxx;
long long a[500100],vis[500100],id[500100];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i-1]){
			cnt++;
			vis[cnt]=a[i];
			id[cnt]=i;
		}
	}
	id[cnt+1]=n+1;
	for(int i=2;i<cnt;i++){
		long long o=m,ans=id[i+1]-id[i];
		for(int k=1;k<id[i];k++){
			long long p=vis[i]-a[k];
			if(p>o)break;
			else{
				o-=p;
				ans++;
			}
		}
		maxx=max(maxx,ans);
	}
	cout<<maxx;
	return 0;
}
