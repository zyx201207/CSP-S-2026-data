#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],f[500010],ans,cnt,k;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	f[1]=k=1;
	for(long long i=2;i<=n;i++){
		cnt=f[i-1]*(a[i]-a[i-1])+cnt;
		if(cnt<=m){
			f[i]=f[i-1]+1;
		}
		else{
			for(long long j=k;j<=i;j++){
				cnt-=a[i]-a[j];
				if(cnt<=m){
					k=j;
					break;
				}
			}
			f[i]=i-k;
			k++;
		}
		ans=max(ans,f[i]);
	}
	cout<<ans;
	return 0;
}

