#include<bits/stdc++.h>
using namespace std;
long long a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	int ma=0,cnt=1;
	for(int i=n;i>=1;i--){
		long long victim=m;
		int j=i;
		while(victim>0&&j>1){
			j--;
			if(victim-(a[i]-a[j])<0){
				break;
			}
			victim=victim-(a[i]-a[j]);
			cnt++;
		}
		ma=max(ma,cnt);
		cnt=1;
	}
	printf("%d",ma);
	return 0;
}