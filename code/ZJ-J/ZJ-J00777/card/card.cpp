#include<bits/stdc++.h>
using namespace std;
int a[5000000],n,m,len,ans[3000000],s[5000000];
bool vis[3000000],f;
int sp(int l,int r){
	while(r<n){
		a[l]=a[r+1];
		l++,r++;
	}
}
int zs(int p,int kk){
	for(int k = kk;k<p;k++){
		if(a[k]=a[p]){
			return k;
		}
	}
}
int main(){
	freopen("card1.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		s[i]=a[i];
	}
	for(int i = 1;i<=n;i++){
		len=n-i+1;
		for(int j = i;j<=n;j++){
			a[j]=s[j];
		}
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++){
			if(vis[a[j]]){
				sp(zs(j,i),j-1);
			}
			vis[a[j]]=1;
			if(j==n){
				for(int q = i;q<=n;q++){
					ans[a[q]]++;
				}
				break;
			}
		}
	}
	for(int i = 1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

