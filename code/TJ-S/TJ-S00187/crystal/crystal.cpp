#include <bits/stdc++.h> 
using namespace std;
long long n,m,a[500005],l = 1000000000000,r=-1000000000000,cnt[500005],f[505][505],ans=-1000000000,d[500005],sum[500005],teshuxingzhi=0,su;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n>>m;
	for (int i =  1;i <= n;i++){
		cin>>a[i];
		l = min(l,a[i]);
		r= max(r,a[i]);
	}
	if (n<=16){
		for (int i = l;i <= r;i++){
			memset(f,0,sizeof(f));
			for (int j = 1;j <= n;j++){
				cnt[j]=i - a[j]; 
			}
//			for (int j = 1;j <= n;j++)cout <<cnt[j]<<' ';
//			cout <<endl;
			long long maxx = -1000000;
			for (int j = 1;j <= n;j++){
				if (cnt[j]<0)continue;
				for (int k=cnt[j];k<=m;k++){
					f[j][k]=max(f[j-1][k],f[j-1][k-cnt[j]]+1);
					maxx=max(maxx,f[j][k]);
				}
			}
			ans=max(ans,maxx);
		}
		cout<<ans;
		return 0;
	}
	if (l +r<=2e5){
		sort(a+1,a+n+1);
//		for (int i = 1;i <= n;i++)cout <<a[i]<<' ';
		for (int i = r;i >= l;i--){
			long long x = m;
			long long s=0;
			su=0;
			for (int j = 1;j<=n;j++){
				if (a[j]>i)break;
				s++;
			}
//			cout <<s<<' ';
			for (int j = s;j>=1;j--){
				long long y = i-a[j];
				if (x-y>=0){
					su++;
					x-=y;
				}
				else{
					break;
				}
			}
			ans=max(su,ans);
		}
		cout <<ans<<endl;
		return 0;
	}
	else{
		sort(a+1,a+n+1);
		long long idx = 0;
		for (int i = n;i>=1;i--){
			idx++;
			if (i!=n)d[idx]=a[i+1]-a[i]+d[idx-1];
			else d[idx]=0;
			sum[idx]=sum[idx-1]+d[idx];
		}
		ans=0;
		for (int i = 1;i <= idx;i++){
			if (sum[i]>m)break;
			ans++;
//			cout <<sum[i]<<' ';
		}
		cout <<ans;
	}
	return 0;
}












































