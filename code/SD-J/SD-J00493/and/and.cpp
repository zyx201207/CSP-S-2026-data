#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m,a[N];
int f[N];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==m){
		for(int i=2;i<=n;i++){
			a[1]&=a[i];
		}
		cout<<a[1];
		return 0;
	}
	if(m==1){
		int ans=0;
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}
	if(m==2 && n<=2000){
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)
					continue;
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	if(n<=20){
		int anss=0;
		for(int i=1;i<=(1<<(n+1))-1;i++){
			int cnt=0;
			memset(f,0,sizeof(f));
			int j=1,k=0,ii=i;
			while(ii>0){
				f[j]=ii%2;
				ii/=2;
				j++;
			}
			for(int l=1;l<=n;l++){
				if(f[l]==1){
					k=l;
					break;
				}
			}
			int t=a[k];
			for(int l=1;l<=n;l++){
				if(f[l]==1){
					t=(t&a[l]);
					cnt++;
				}
			}
			if(cnt==m)
				anss=max(anss,t);
		}
		cout<<anss;
		return 0;
	}
	int ans=2147483647;
	for(int i=1;i<=n;i++)
		ans=min(ans,a[i]);
	cout<<ans;
	return 0;
}
