#include<bits/stdc++.h>
using namespace std;
int n,m,a[5010],sum[5010];
int q[5010],tt;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		tt=1;
		memset(q,0,sizeof(q));
		for(int j=i;j<=n;j++){		
			for(int l=1;l<tt;l++){
				if(q[l]==a[j])tt=l;
			}
			q[tt++]=a[j];

	 	}
		for(int j=1;j<tt;j++){
			sum[q[j]]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<sum[i]<<" ";
	return 0;
}