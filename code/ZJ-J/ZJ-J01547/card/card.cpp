#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500010];
int z[500010];
int vis[500010];
int sum[500010];
int d[500010];
int f[500010];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >>n>>m;
	bool flaga=1;
	for(int i=1;i<=n;i++){
		cin >>a[i];
		if(a[i]<a[i-1])flaga=0;
	}
	if(flaga){
		for(int i=1;i<=n;i++){
			f[a[i]]=max(f[a[i]],i);
		}
		for(int i=1;i<=m;i++)cout <<f[i]<<' ';
	}else{
		int len=0;
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		memset(z,0,sizeof(z));
		len=0;
		for(int j=i;j<=n;j++){
			int f=0;
			for(int k=1;k<=len;k++){
				if(z[k]==a[j]){
					f=k;
					break;
				}
			}
			if(f!=0){
				int l=f+1;
				while(z[l]!=0){
					z[l]=0;
					l++;
				}
				len=f;
			}else {
				len++;
				z[len]=a[j];
			}
		}
		for(int j=1;j<=len;j++){
			vis[z[j]]=1;
		}
		for(int j=1;j<=m;j++){
			sum[j]+=vis[j];
		}
	}
	for(int i=1;i<=m;i++){
		cout <<sum[i]<<' ';
	}
	}
	
	return 0;
}
