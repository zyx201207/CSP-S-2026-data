#include<bits/stdc++.h>
using namespace std;
int cnt[200050],r;
char c[200050],rc;
int ne;
int n;
long long sum;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	ne=n;
	for(int i=1;i<=n;i++){
		cin>>cnt[i]>>c[i];
		sum+=cnt[i];
	}
	for(int i=1;i<=n;i++){
		int ncnt=cnt[i];
		if(ncnt<=r){
			if(c[i]!=rc){
				ans+=ncnt;
			}
			r-=ncnt;
			// cout<<i<<' '<<ans<<' '<<r<<' '<<ne<<'\n';
			if(ne==i-1){
				break;
			}
			if((i+1>ne&&cnt[i+1]>r)){
				break;
			}
			continue;
		}
		else{
			ncnt-=r;
			if(c[i]!=rc){
				ans+=r;
			}
			r=0;
		}
		while(ncnt>0){
			ncnt-=cnt[ne];
			if(c[i]!=c[ne]){
				if(ncnt<0){
					ans+=ncnt+cnt[ne];
				}
				else{
					ans+=cnt[ne];
				}
			}
			ne--;
		}
		if(ncnt<0){
			r=-ncnt;
			rc=c[ne+1];
		}
		if(ne==i-1){
			break;
		}
		// cout<<i<<' '<<ans<<' '<<r<<' '<<ne<<'\n';
		if((i+1>ne&&cnt[i+1]>r)){
			break;
		}
	}
	cout<<ans;
	return 0;
}