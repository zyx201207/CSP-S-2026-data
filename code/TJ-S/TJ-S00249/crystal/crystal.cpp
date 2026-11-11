#include <bits/stdc++.h>
using namespace std;
const int N=5e6+5;
long long n,m;
long long a[N],d[N];
long long l=1;
long long s=0;
long long an=0,ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(long long i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	a[0]=a[1];
	for(long long r=1;r<=n;r++){
		d[r]=a[r]-a[r-1];
		s+=d[r]*an;
		an++;
		if(s>m){
			for(long long j=l;j<=r;j++){
				if(s<=m){
					l=j;
					break;
				}
				s-=a[r]-a[j];
				an--;
			}
		}
		if(an>ans) ans=an;
	}
	cout <<ans;
	return 0;
}

