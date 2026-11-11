#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 2e6 + 5;
ll c,t,n,d,L[N + 5],R[N + 5],a[N + 5];
//l,r表示从哪个方向跳过来 
ll dt[N + 5];
vector <ll> gl[N + 5],gr[N + 5],el[N + 5],er[N + 5];
ll fl[N + 5],fr[N + 5],ans;
struct info{
	ll v,sum;
	info operator + (const info &x){
		if(v == x.v) return (info){v,sum+x.sum};
		if(v < x.v) return *this;
		return x;
	}
};
info lo[N + 5];
#define lb(x) ((x)&(-(x)))
void add(ll u,info w){
	while(u <= n){
		lo[u] = lo[u] + w;
		u += lb(u);
	}
}
info query(ll u){
	info an = (info){(ll)(1e9),0ll};
	while(u){
		an = an + lo[u];
		u -= lb(u);
	}
	return an;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&d);
		for(ll i = 1;i <= n;++i) scanf("%lld",&a[i]);
	//	printf("n %lld nn %lld d %lld\n",n,n*n,d);
	//	if(d != 14) continue;
	/*	if(n <= 10){
			printf("%lld %lld\n",n,d);
			for(ll i = 1;i <= n;++i){
				printf("%lld ",a[i]);
			}
			printf("\n");
		} */
		ll l = 1;
		for(ll i = 1;i <= n;++i){
			while(a[i] - a[l] > d) ++l;
			L[i] = l;
		}
		ll r = n;
		for(ll i = n;i >= 1;--i){
			while(a[r] - a[i] > d) --r;
			R[i] = r;
		}
		for(ll i = 2;i <= n;++i){
			dt[i] = a[i] - a[i-1];
		}
		bool flag = 1;
		for(ll i = 3;i <= n;++i){
			if(dt[i] != dt[i-1]) flag = 0;
		}
		if(flag){
			if(n <= 2){
				printf("0\n");
				continue;
			}
			d /= dt[2];
			if(d <= 1){
				printf("0\n");
				continue;
			}
			ll ne = d * 2 - 1;
			if(ne >= n) printf("0\n");
			else printf("%lld\n",n-ne);
			continue;
		}
		if(n <= 5005){
			ll an = 0;
			for(ll i = n;i >= 1;--i){
				for(ll j = 1;j <= n;++j){
					lo[j].v = (ll)(1e9);
					lo[j].sum = 0;
				}	 
				add(i,(info){0ll,1ll});
				for(ll j = i - 1;j >= 1;--j){
					info x = query(R[j]);
					if(x.sum == 2){
						++an;
					}
					++x.v;
					add(j,x);
				}			
			}
			printf("%lld\n",an);
			continue;
		}

/*		for(ll i = 1;i <= n;++i){
			printf("I %lld l %lld r %lld\n",i,L[i],R[i]);
		}*/
		for(ll i = 1;i <= n;++i){
			vector <ll>().swap(el[i]);
			vector <ll>().swap(er[i]);
			vector <ll>().swap(gl[i]);
			vector <ll>().swap(gr[i]);
		}
		for(ll i = 1;i <= n;++i){
			//往左跳 
			if(L[i] != i){
				if(R[L[i]] == i){
					gr[L[i]].push_back(i);
				}
				else{
					er[L[i]].push_back(i);
				}
			}
			//往右跳 
			if(R[i] != i){
				if(L[R[i]] == i){
					gl[R[i]].push_back(i);
				}
				else{
					el[R[i]].push_back(i);
				}
			}			
		}
		for(ll i = 1;i <= n;++i){
			fl[i] = 1 + (ll)(el[i].size());
			for(ll j : gl[i]){
				fl[i] += fl[j]; 
			}
		}
		for(ll i = n;i >= 1;--i){
			fr[i] = 1 + (ll)(er[i].size());
			for(ll j : gr[i]){
				fr[i] += fr[j]; 
			}
		}		
		ans = 0;
		for(ll i = 1;i < n;++i){
			ll al = 0,ar = 0;
			for(ll j : el[i+1]){
				if(j != i) ++al;
			}
			for(ll j : gl[i+1]){
				if(j != i) al += fl[j];
			}
			for(ll j : er[i]){
				if(j != i+1) ++ar;
			}
			for(ll j : gr[i]){
				if(j != i+1) ar += fr[j];
			}	
			ans += al * ar;	
		//	printf("i %lld i + 1 %lld al %lld ar %lld\n",i,i+1,al,ar);	
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*0 1 10 22
0 7 14 21 28 35 42 49 56 63 */

/*0 2
4 2
1 2 3 4
5 2
1 2 3 4 5*/

