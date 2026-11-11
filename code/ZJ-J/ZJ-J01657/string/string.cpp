#include<bits/stdc++.h>
using namespace std;
int n;
int a[200010];
long long aa[200010];
char c[200010];
long long l=1,r;
long long len;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
		r+=a[i];
		len+=a[i];
	}
	for(int i=1;i<=n;i++){
		aa[i]=aa[i-1]+a[i];
	}
	int ll=1;
	int rr=n;
	while(l<=r){
		if((aa[ll]-l+1)<=(r-aa[rr-1])){
			if(c[ll]!=c[rr]){
				ans+=(aa[ll]-l+1);
			}
			long long tot=(aa[ll]-l+1);
			if((aa[ll]-l+1)==(r-aa[rr-1])){
				rr--;
			}
			l+=tot;
			ll++;
			r-=tot;
		}else{
			if(c[ll]!=c[rr]){
				ans+=(r-aa[rr-1]);
			}
			long long tot=(r-aa[rr-1]);
			l+=tot;
			r-=tot;
			rr--;
		}
	}
	cout<<ans;
	return 0;
}