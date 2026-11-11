#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=5e5+5,M=3e5+5;
int n,m,a[N],ans[M],lst[M],now[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int k=0;
		for(int j=i;j<=n;j++){
			k++;
			if(lst[a[j]]==0){
				now[k]=a[j];lst[a[j]]=k;
			}
			else {
			for(int l=lst[a[j]]+1;l<k;l++)lst[now[l]]=0;
			k=lst[a[j]];
			}
		}
		for(int i=1;i<=k;i++)ans[now[i]]++;
		memset(lst,0,sizeof(lst));
		memset(now,0,sizeof(now));
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
