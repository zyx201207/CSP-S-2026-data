#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ll n,m;
	scanf("%lld%lld",&n,&m);
	vector<ll> a(n+1),ans(m+1,0);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	vector<ll> b(n+1);
	vector<bool> t(m+1);
	ll l=1,r=0;
	for(ll v=1;v<=n;v++){
		fill(b.begin(),b.end(),0);
		fill(t.begin(),t.end(),0);
		l=v;r=v-1;
		for(ll i=v;i<=n;i++){
			if(l>r){
				b[++r]=a[i];
				t[a[i]]=true;
				continue;
			}
			if(t[a[i]]){
				int k=l;
				while(k<=r){
					if(b[k]==a[i])break;
					k++;
				}
				for(int p=k;p<=r;p++)t[b[p]]=0;
				r=k-1;
			}
			b[++r]=a[i];
			t[a[i]]=1;
		}
		for(ll p=l;p<=r;p++)ans[b[p]]++;
		//printf("\n");
	}
	for(ll i=1;i<=m;i++)printf("%lld ",ans[i]);
	return 0;
}/*4 3
1 2 1 3*/
