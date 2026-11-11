#include<bits/stdc++.h>
using namespace std;
#define int long long
int n , m , a[200005] , st[400005] , h , ans[300005] ;
int tmp[300005] ;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	memset(tmp,-1,sizeof(tmp));
	for(int i=1;i<=n;i++){
		st[++h]=a[i];
		if(tmp[a[i]]>=0){
			tmp[st[h]]--;
			h--;
			while(h>0&&st[h]!=a[i]){
				// cout << h << "* " ;
				tmp[st[h]]--;
				h--;
			}
		}
		tmp[a[i]]++;
		for(int i=1;i<=h;i++)ans[st[h]]++;
	}
	for(int i=1;i<=m;i++)printf("%lld ",ans[i]);
	return 0;
}