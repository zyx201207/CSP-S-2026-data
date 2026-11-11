#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,aa[501000],N,tot;
struct node{
	int s,num;
}a[501000],ans[501000];
int answer(int now){
	int res=0;
	for(int i=1;i<=n;i++){
		res+=abs(a[i ].s-a[now].s)*a[i].num;
	}
	return res;
}
bool cmp(const node &A,const node &B){
	return A.s<B.s;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&N,&m);
	for(int i=1;i<=N;i++){
		scanf("%lld",&aa[i]);
	}
	for(int i=0;i<=N;i++){
		a[i].s=-1e13;
	}
	sort(aa+1,aa+N+1);
	for(int i=1;i<=N;i++){
		if(a[n].s!=aa[i]){
			a[++n].s=aa[i];
			a[n].num=1;
		}
		else{
			a[n].num++;
		}
	}
	int l=0,r=n+1;
	while(l+1<r){
		int mid=(l+r)/2;
		int ns=answer(mid);
		int ls=answer(mid-1);
		int rs=answer(mid+1);
		if(ls<ns){
			r=mid;
		}
		else if(rs<ns){
			l=mid;
		}
		else{
			l=mid;
			break;
		}
	}
	if(answer(r)<answer(l)){
		l=r;
	}
	for(int i=1;i<=n;i++){
		ans[i].s=abs(a[i].s-a[l].s);
		ans[i].num=a[i].num;
	}
	sort(ans+1,ans+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(m>=ans[i].s){
			if(m>=ans[i].s*ans[i].num){
				m-=ans[i].s*ans[i].num;
				tot+=ans[i].num;
			}
			else{
				tot+=m/ans[i].s;
				break;
			}
		}
		else{
			break;
		}
	}
	printf("%lld",tot);
	return 0;
} 
