#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll ma=1e5+5;
ll n,m,a[ma],aa[ma];
inline ll read(){
	ll x=0,f=1;
	char c;
	c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+(c-'0');
		c=getchar();
	}
	return x*f;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();
	m=read();
	//cout<<m;
	ll cha=0;
	bool b=0;
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(i==2){
			cha=a[i]-a[i-1];
		}else if(i>2){
			if(cha!=a[i]-a[i-1]) b=1;
		}
		aa[i]=a[i];
	}
	if(!b){
		//cout<<1;
		ll s=0;
		bool w=0;
		for(int i=1;i<n;i++){
			s+=i*cha;
			//cout<<i<<" "<<s<<endl;
			if(s>m){
				printf("%lld",i);
				w=1;
				break;
			}else if(s==m){
				printf("%lld",i+1);
				w=1;
				break;
			}
		}
		if(!w) printf("%lld",n);
		//cout<<(m/cha)+1;
		return 0;
	}
	sort(a+1,a+1+n);
	ll mm=unique(a+1,a+1+n)-a-1;
	ll cnt=0;
	ll sum=0,t=0,ti=0,s[ma]={},ss=0;
	//cout<<m;
	for(ll i=2;i<=mm;i++){
		//cout<<i<<" "<<a[i]<<endl;
		int x=lower_bound(aa+1,aa+1+n,a[i])-aa;
		int y=upper_bound(aa+1,aa+1+n,a[i])-aa-1;

		s[i]=y-x+1;
		if(s[i-1]==0){
			ll xx=lower_bound(aa+1,aa+1+n,a[i-1])-aa;
			ll yy=upper_bound(aa+1,aa+1+n,a[i-1])-aa-1;
			s[i-1]=yy-xx+1;
		}
		
		ss+=s[i-1];
		//cout<<s<<endl;
		//cout<<a[i+1]<<" "<<a[i]<<endl;
		//cout<<t<<endl;
		if(t+(ss*(a[i]-a[i-1]))>=m){
			//cout<<i<<" "<<(m)<<endl;
			sum=max(max(ti,s[i]+((m-t)/(a[i]-a[i-1]))),sum);
			t+=(ss*(a[i]-a[i-1]));
			ti+=s[i];

			while(t>=m&&cnt<=i){
				cnt++;
				t-=s[cnt]*(a[cnt+1]-a[cnt]);
				ti-=s[cnt];
				//cout<<cnt;
				//cout<<i<<" "<<s[cnt];
			}
		}else{
			ti=ss+s[i];
			//cout<<ti<<endl;
			t+=(ss*(a[i]-a[i-1]));
		}
	}
	cout<<max(ti,sum);
	return 0;
}
//5 8 -3 -1 2 2 7
