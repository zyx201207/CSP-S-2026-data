#include<bits/stdc++.h>
using namespace std;
const int N=500010;
const int M=300010;
int n,a[N],vis[M],cnt,tong[M],m,b[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(vis,-1,sizeof vis);
	memset(tong,0,sizeof tong);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cnt=0;
		memset(vis,-1,sizeof vis);
		for(int j=i;j<=n;j++){
			if(vis[a[j]]!=-1){
				cnt=vis[a[j]]-1;
				for(int k=cnt+1;k<=j-1;k++){
					vis[b[k]]=-1;
					b[k]=-1;
				}
			}
			b[++cnt]=a[j];
			vis[a[j]]=cnt;
		}
		for(int j=1;j<=cnt;j++){
			tong[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<tong[i]<<" ";
	}
	return 0;
}
