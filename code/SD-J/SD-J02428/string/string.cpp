#include<bits/stdc++.h>
using namespace std;
long long n,a[300005],s,len;
char c[300005];
long long xs(long long a,long long b){
	if(a%b>0){
		return a/b+1;
	}
	return a/b;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	len=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
	}
	s=0;
	long long l=0,r=len+1,ll=1,rr=n,zx;
	while(l<len/2&&r>xs(len,2)+1){
		//cout<<l<<' '<<r<<endl;
		if(c[ll]!=c[rr]){
			//cout<<"bt"<<' '<<ll<<' '<<a[ll]<<' '<<rr<<' '<<a[rr]<<endl;
			zx=min(a[ll],a[rr]);
			s+=min(a[ll],a[rr]);
			a[ll]-=zx,a[rr]-=zx;
			l+=zx,r-=zx;
			if(a[ll]==0){
				ll++;
			}
			if(a[rr]==0){
				rr--;
			}
		}
		else{
			//cout<<"xt"<<' '<<ll<<' '<<a[ll]<<' '<<rr<<' '<<a[rr]<<endl;
			zx=min(a[ll],a[rr]);
			a[ll]-=zx,a[rr]-=zx;
			l+=zx,r-=zx;
			if(a[ll]==0){
				ll++;
			}
			if(a[rr]==0){
				rr--;
			}
		}
	}
	cout<<s;
	return 0;
}
