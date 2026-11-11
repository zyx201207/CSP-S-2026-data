#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N=2e5+5;
pair<ll,char> a[N];
pair<ll,char> b[N];
int cntb=0;
pair<ll,char> c[N];
int cntc=0;
int n;
ll sum=0,hf=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].first;
		cin>>a[i].second;
		sum+=a[i].first;
	}
	hf=sum/2;
	ll tmp=0;
	int hh=0;
	for(int i=1;i<=n;i++){
		if(tmp+a[i].first<hf){
			tmp+=a[i].first;
			c[++cntc]=a[i];
		}else{
			c[++cntc]=make_pair(hf-tmp,a[i].second);
			a[i].first-=c[cntc].first;
			if(a[i].first==0){
				a[i+1].first-=(sum&1);
				hh=i+1;
			}else{
				a[i].first-=(sum&1);
				hh=i;
			}
			break ;
		}
	}
	for(int i=1;i<=cntc;i++){
		c[i].first+=c[i-1].first;
	}
	for(int i=n;i>=hh;i--){
		b[++cntb]=a[i];
		b[cntb].first+=b[cntb-1].first;
	}
	ll cw=1,bw=1;
	ll ans=hf;
	while(cw<=cntc && bw<=cntb){
		if(b[bw].second==c[cw].second){
			int r=min(c[cw].first,b[bw].first);
			int l=max(c[cw-1].first,b[bw-1].first)+1;
			if(r-l+1>0) ans-=(r-l+1);
		}
		if(b[bw].first<c[cw].first){
			bw++;
		}else{
			cw++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
