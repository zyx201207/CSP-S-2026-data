#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans[300005];
vector<long long>t[300005],bt[300005];
bool flaga=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]<a[i-1]){
			flaga=0;
		}
	}
	if(flaga){
		for(int i=1;i<=n;i++){
			long long gc[300005]={},cnt[300005]={},back;
			for(int j=i;j<=n;j++){
				if(back>=0&&a[j]==gc[back]){
					back--;
				}
				else{
					gc[++back]=a[j];
				}
			}
			for(int j=1;j<=back;j++){
				cnt[gc[j]]=1;
			}
			for(int j=1;j<=m;j++){
				ans[j]+=cnt[j];
			}
		}
		for(int i=1;i<=m;i++){
			printf("%lld ",ans[i]);
		}
	}
	else if(n==m){
		for(int i=1;i<=n;i++){
			ans[a[i]]+=i;
		}
		for(int i=1;i<=m;i++){
			printf("%lld ",ans[i]);
		}
	}
	return 0;
}
