//zhangqinlu SN-S00501
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=500005;
int n;
ll m,a[N],cnt[N],s[N];
ll maxn=-1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(cnt,0,sizeof cnt);
	cin>>n>>m;
	for (int i=1;i<=n;i++) 
		cin>>a[i];
	sort(a+1,a+1+n);
	s[0]=0;
	for (int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for (int i=1;i<=n;i++){
		for (int l=1;l<=n;l++){
			for (int r=l;r<=n;r++){
				cnt[i]=s[r]-s[l-1];
				ll b=cnt[i]+m,c=r-l+1;
				ll d=b/c;
				if (d*c!=b) continue;
				else{
					ll s=0;
					for (int j=l;j<=r;j++){
						s+=abs(a[j]-d);
						
					}
					if (s>m){
						break;
					}
				}
				maxn=max(maxn,c);
			}
		}
	}
	cout<<maxn<<'\n';
	return 0;
}

