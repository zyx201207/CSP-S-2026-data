#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans,a[200010],b[200010],c[200010],tot,cnt;
int pd(int x){
	int sum=0;
	for(int i=1;i<=n;i++)	
		if((a[i]&(1<<x))!=0) sum++;
	return sum;
}
int pd2(int x){
	int sum=0;
	for(int i=1;i<=tot;i++)	
		if((b[i]&(1<<x))!=0) sum++;
	return sum;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int j=30;j>=0;j--)
		if(pd(j)>=m){
			ans+=(1<<j);
			tot=0;
			for(int i=1;i<=n;i++)	
			if((a[i]&(1<<j))!=0) tot++,b[tot]=a[i];				
			for(int k=j-1;k>=0;k--)
				if(pd2(k)>=m){
					ans+=(1<<k);
					cnt=0;
					for(int i=1;i<=tot;i++)	
						if((b[i]&(1<<k))!=0) cnt++,c[cnt]=b[i];
					for(int i=1;i<=cnt;i++) b[i]=c[i];
					tot=cnt;
				}
			cout<<ans;
			return 0;
		}
	return 0;
}