#include <bits/stdc++.h>
using namespace std;
const long long N=5e5+5;
long long n,m;
long long a[N],s[N];
long long t[1005];
bool fg1,fg2;
long long maxx,minn=1e12+5;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	fg1=fg2=true;
	for (long long i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,abs(a[i]));
		minn=min(minn,a[i]);
		if (a[i] != i) fg1=false;
		if (i >= 3){
			if (a[i]-a[i-1] != a[i-1]-a[i-2]){
				fg2=false;
			}
		}
	}
	if (n <= 16){
		long long ans=-1;
		for (long long i=1;i<=n;i++){
			long long cnt=0;
			for (long long j=1;j<=n;j++){
				s[j]=abs(a[j]-a[i]);
			}
			sort(s+1,s+1+n);
			long long q=m;
			for (long long j=1;j<=n;j++){
				if (s[j] > q) break;
				else{
					cnt++;
					q-=s[j];
				}
			}
			ans=max(ans,cnt);
		}
		cout<<ans;
	}else if (maxx <= 100){
		long long ans=0;
		for (long long i=1;i<=n;i++){
			a[i]+=100;
			t[a[i]]++;
		}
		for (long long i=minn+100;i<=maxx+100;i++){
			long long cnt=t[i],p=m,j=0;
			while (++j){
				if (i+j <= maxx+100){
					long long k=t[i+j];
					if (p >= j*k){
						p-=j*k;
						cnt+=k;
					}else if (p >= j){
						long long x=p/j;
						p-=x*j;
						cnt+=x;
					}
				}
				if (i-j >= 0){
					long long k=t[i-j];
					if (p >= j*k){
						p-=j*k;
						cnt+=k;
					}else if (p >= j){
						long long x=p/j;
						p-=x*j;
						cnt+=x;
					}
				}
				if (p < j) break;
			}
			ans=max(ans,cnt);
		}
		cout<<ans;
	}else if (fg1){
		long long mid=(1+n)/2;
		long long ans=1,q=m;
		for (long long i=mid+1;i<=n;i++){
			long long p=a[i]-a[mid];
			if (q >= 2*p){
				ans+=2;
				q-=(2*p);
			}else if (q >= p){
				ans+=1;
				q-=p;
			}else if (q < p){
				break;
			}
		}
		cout<<ans;
	}else if (fg2){
		long long mid=(1+n)/2;
		long long ans=1,q=m;
		for (long long i=mid+1;i<=n;i++){
			long long p=abs(a[i]-a[mid]);
			if (q >= 2*p){
				ans+=2;
				q-=(2*p);
			}else if (q >= p){
				ans+=1;
				q-=p;
			}else if (q < p){
				break;
			}
		}
		cout<<ans;
	}
	return 0;
}
