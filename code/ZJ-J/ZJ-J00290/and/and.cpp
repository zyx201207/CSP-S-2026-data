#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005][35];
int cnt[35],v[200005],num[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	int fix=n-m;
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		num[i]=x;
		int l=1;
		for(int j=1;j<=30;j++){
			cnt[j]++;
		}
		while(x){
			a[i][l]=x%2;
			cnt[l]-=x%2;
			x/=2;
			l++;
		}
	}
	int ans=0;
	for(int i=30;i>=1;i--){
		ans+=(1<<i-1);
		if(cnt[i]<=fix){
			fix-=cnt[i];
			for(int j=1;j<=n;j++){
				if(a[j][i]==0&&v[j]==0){
					v[j]=1;
					for(int k=i;k>=1;k--){
						if(a[j][k]==0){
							cnt[k]--;
						}
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(v[i]==0){
			ans&=num[i];
		}
	}
	printf("%d",ans);
	return 0;
}
