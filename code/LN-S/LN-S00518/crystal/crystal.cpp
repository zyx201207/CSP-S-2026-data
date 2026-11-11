#include<bits/stdc++.h>
using namespace std;
const int N=5010;
int n,m;
int a[N];
int ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		int tot=m;
		int need=0;
		for(int j=i-1;j>=1;j--){
			need=a[i]-a[j];
			if(need>=tot){
				ans=max(ans,i-j+1);
				break;
			}
			tot-=need;
		}
	}
	printf("%d",ans);
	return 0;
}
