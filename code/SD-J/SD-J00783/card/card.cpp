#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5,M=3e5+5;
int n,m,a[N],b[M],p[N],cnt,f;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		if(a[i]>a[i+1]){
			f=1;
		}
	}
	if(f==0){
		for(int i=1;i<=n;i++){
			memset(p,0,sizeof(p));
			cnt=0;
			for(int j=i;j<=n;j++){
				if(p[cnt]==a[j]){
					p[cnt]=0;
				}
				p[++cnt]=a[j];
			}
			for(int j=1;j<=cnt;j++){
				b[p[j]]++;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<b[i]<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		memset(p,0,sizeof(p));
		cnt=0;
		for(int j=i;j<=n;j++){
			for(int k=1;k<=j-1;k++){
				if(p[k]==a[j]){
					for(int l=k;l<=j;l++){
						p[l]=0;
					}
				}
			}
			p[++cnt]=a[j];
		}
		for(int j=1;j<=cnt;j++){
			b[p[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
