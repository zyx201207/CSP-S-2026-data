#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
long long a[N],s[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,mi=LONG_LONG_MAX,ma=LONG_LONG_MIN,ans=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		ma=max(a[i],ma);
		mi=min(a[i],mi);
	}
	sort(a,a+n);
	if(a[1]-a[0]==a[3]-a[2]&&a[n-1]-a[n-2]==a[3]-a[2]){
		long long gc;
		gc=abs(a[1]-a[0]);
		ans=m/gc;
		cout<<ans<<endl;
		return 0;
	}
	for(int i=mi;i<=ma;i++){
		long long s=0,sj=0;
		for(int j=0;j<n;j++){
			if(i>=a[j]){
				if(s+(i-a[j])<=m){
				s+=(i-a[j]);
				sj++;
				}
			}
			else{
				break;
			}
		}
		ans=max(sj,ans);
	}
	cout<<ans<<endl;
	return 0;
}
