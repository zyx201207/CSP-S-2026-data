#include<bits/stdc++.h>
using namespace std;
#define int long long
const int Maxn=5e5+10,Maxm=3e5+10;
int n,m;
int a[Maxn],sum[Maxn],vis[Maxm],nsum[Maxn],ans[Maxn];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1])	flag=0;
	}
	if(flag){//特殊性质A 4pts
		for(int i=2;i<=n+1;i++){
			if(a[i]!=a[i-1]){
				cout<<i-1<<" ";
			} 
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)	vis[j]=0;
		for(int j=i;j<=n;j++){
			sum[j-i+1]=a[i+j-i];
		}
		int len=n-i+1,nlen=0;
		for(int j=1;j<=len;j++){
			if(vis[sum[j]]==0){
				vis[sum[j]]++;
				nsum[++nlen]=sum[j];
			}else{//否则回溯至上一次出现sum[j]的位置 
				nlen++;
				while(nlen>=1){
					nlen--;
					if(nsum[nlen]==sum[j]){
						break;
					}
					vis[nsum[nlen]]--;
				}
			}
		}
		for(int j=1;j<=nlen;j++){
			ans[nsum[j]]++;
		}
	}
	for(int i=1;i<=m;i++)	cout<<ans[i]<<" ";
	return 0;
} 
/*
4 3
1 2 1 3
*/
