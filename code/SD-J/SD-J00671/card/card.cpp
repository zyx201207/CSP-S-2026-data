#include<bits/stdc++.h>
using namespace std;
int n,m,a[5005],b[5005],cnt,nw[5005],top,k;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >>a[i];
		if (a[i]<a[i-1]) k=1;
	}
	if (!k){
		for (int i=n;i>=1;i--) cout << i << ' ';
		return 0;
	}
	for (int p=1;p<=n;p++){
		memset(b,0,sizeof(b));
		for (int i=1;i<=n;i++){//枚举到i张牌 
			cnt=0;
			for (int j=1;j<=n;j++){//牌桌上有无 
				if (b[j]==a[i]){
					cnt=1;
					for (int k=j;k<=n;k++) top--;
					b[++top+1]=a[i];
				}
			}
			if (!cnt) b[++top]=a[i];
		}
		for (int i=p;i<=n;i++){
			for (int j=1;j<=m;j++){
				if (b[j]==i) nw[i]++;
			}
		}
	}
	for (int i=1;i<=m;i++) cout << nw[i] << ' ';
	return 0;
}
