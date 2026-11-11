#include<bits/stdc++.h>
#define L(i,l,r,d) for(int (i)=(l);(i)<=(r);(i)+=(d))
#define R(i,l,r,d) for(int (i)=(r);(i)>=(l);(i)-=(d))

using namespace std;
const int N=5e5+5;

typedef long long i64;

void solve();
int n,ans;
i64 m,ans2;
vector<i64> a,b;

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int Test=1;
	//scanf("%d",&Test);
	while(Test--) solve();
	return 0;
}

void solve(){
	scanf("%d%lld",&n,&m);
	a.resize(n+1);
	bool ok1=1,ok2=1;
	L(i,1,n,1){
		scanf("%lld",&a[i]);
		if(i!=a[i]) ok1=0;
		if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2]) ok2=0;
		b.push_back(a[i]);
	}
	if(ok1){
		i64 l=0,r=1e18;
		__int128 x;
		while(l+1<r){
			x=(l+r)/2;
			__int128 val=x*(x+1)/2;
			if(val<=m){
				l=x;
			}
			else r=x;
		}
		vector<int> p;
		l++;
		while(l){
			p.push_back(l%10);
			l/=10;
		}
		reverse(p.begin(),p.end());
		for(int i:p) printf("%d",i);
		puts("");
		return;
	}
	if(ok2){
		i64 k=a[2]-a[1];
		i64 l=0,r=1e18;
		__int128 x;
		while(l+1<r){
			x=(l+r)/2;
			__int128 val=x*k*(x+1)/2;
			if(val<=m){
				l=x;
			}
			else r=x;
		}
		vector<int> p;
		l++;
		while(l){
			p.push_back(l%10);
			l/=10;
		}
		reverse(p.begin(),p.end());
		for(int i:p) printf("%d",i);
		puts("");
		return;
	}
	sort(a.begin()+1,a.end());
	sort(b.begin(),b.end());
	b.erase(unique(b.begin(),b.end()),b.end());
	for(i64 x:b){
		i64 cnt=0;
		int tot=0;
		int id=lower_bound(a.begin()+1,a.end(),x+1)-a.begin()-1;
		for(int i=id;i>=0;i--){
			if(cnt+x-a[i]<=m){
				cnt+=x-a[i];
				tot++;
			}
			else break;
		}
		if(cnt<=m) ans=max(ans,tot);
	}
	printf("%d\n",ans);
}