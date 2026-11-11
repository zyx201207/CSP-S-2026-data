#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],c[300005],cnt[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==1){
		cout<<n;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(cnt[a[j]]==0){
				cnt[a[j]]++;
			}
			else{
				int k=j-1;
				while(a[k]!=a[j]){
					cnt[a[k]]=0;
					k--;
				}
				cnt[a[j]]=1;
			}
		}
		for(int j=1;j<=m;j++){
			c[j]+=cnt[j];
			if(i==n)cout<<c[j]<<' ';
			cnt[j]=0;
		}
	}
	return 0;
}