#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500007],s[500007],l,cnt[300007];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n-1;i++){
		l=1;
		s[1]=a[i];
		for(int j=i+1;j<=n;j++){
			bool f=1;
			for(int k=1;k<=l;k++){
				if(s[k]==a[j]){
					l=k;
					f=0;
					break;
				}
			}
			if(f){
				l++;
				s[l]=a[j];
			}
		}
		for(int j=1;j<=l;j++){
			cnt[s[j]]++;
		}
		memset(s,0,sizeof(s));
	}
	cnt[a[n]]++;
	for(int i=1;i<=m;i++){
		printf("%lld ",cnt[i]);
	}
	return 0;
}
