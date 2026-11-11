#include <bits/stdc++.h>
using namespace std;
long long n,a[200005],ma,len,l,r,sum[200005],k,h,lh,rh,ans;
char c[200005];
string s;
int hw(string s){
    int ans=0;
	for(int i=0;i<len/2;i++){
		if(s[i]!=s[len-i-1]) ans++;
	}	
	return ans;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i]>>c[i];
    	ma=max(a[i],ma);
	}
	if(ma<=500){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i];j++){
				s+=c[i];
			}
		}
		len=s.size();
		cout<<hw(s);
	}else{
		for(int i=1;i<=n;i++)	sum[i]=sum[i-1]+a[i];
		for(int i=1;i<=n;i++){
			if(sum[i]>=ceil(sum[n]*1.0/2.0)){
				k=sum[n]/2-sum[i-1];
				h=i;
				break;
			}
		}
		l=sum[n]/2-sum[h-1],r=sum[h]-ceil(sum[n]/2.0*1.0);
		lh=rh=h;
		if(l==0){
			lh--;
			l=a[lh];
		}
		if(r==0){
			rh++;
			r=a[rh];
		}
		for(;lh>=1&&rh<=n;){
			if(c[lh]!=c[rh]) ans+=min(l,r);
			if(l<r){
				lh--;
				r-=l;
				l=a[lh];
			}else if(l>r){
				rh++;
				l-=r;
				r=a[rh];
			}else{
				lh--,rh++;
				l=a[lh],r=a[rh];
			}
		}
		cout<<ans;
	}
	return 0;
}

