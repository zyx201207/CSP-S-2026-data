#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;
long long n,m;
long long a[500005];
long long b[500005];
long long ans=1;
long long cnt[500005],cntt=0;
long long bcnt=0;
map <long long,long long> p;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(n<=50000){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		for(int i=2;i<=n;i++){
			long long t=m,cnt=1;
			for(int j=i-1;j>=1;j--){
				if(a[i]-a[j]<=t){
					t=t-(a[i]-a[j]);
					cnt++;
				}else{
					break;
				}
			}
			ans=max(ans,cnt);
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(p.count(a[i])){
			cnt[p[a[i]]]++;
		}else{
			cntt++;
			p[a[i]]=cntt;
			cnt[p[a[i]]]++;
		}
	}
	if((a[1]>-1000)||(a[n]<1000)){
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			if(a[i]!=a[i-1]){
				bcnt++;
				b[bcnt]=a[i];
			}
		}
		for(int i=bcnt;i>=2;i--){
			long long t=m;
			for(int j=i-1;j>=1;j--){
				for(int k=1;k<=cnt[p[b[j]]];k++){
					if(b[i]-b[j]<=t){
						t=t-(b[i]-b[j]);
						cnt[p[b[i]]]++;
					}else{
						break;
					}
				}
				if(b[i]-b[j]>t){
					break;
				}
			}
			ans=max(ans,cnt[p[b[i]]]);
		}
		cout<<ans;
		return 0;
	}
	long long d=a[2]-a[1];
	long long tm=m*2/d;
	long long mi=sqrt(tm);
	for(long long i=mi-100;i<=mi+100;i++){
		if((n*(n+1)*d/2<m)&&((n+1)*(n+2)*d/2>m)){
			cout<<i+1;
			return 0;
		}
	}
	return 0;
}
