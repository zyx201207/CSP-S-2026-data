#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define pii pair<int,int>
#define xx first
#define yy second
const int N=2e5+10;
int a[N];
int qpow(int a,int b){
	ll ans=1;
	while(b){
		if(b&1){
			ans=ans*a;
		}
		a*=a;
		b>>=1;
	}
	return ans;
}
int c[33];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	bool okb=1;
	if(m==1) {
		cout<<0<<endl;
		return 0;
	}
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]!=i-1) okb=0;
	}int xx=1,aa=0;
	for(int i=1;i<=n;++i){
		xx=1;
		while(a[i]){
			if(a[i]&1) c[xx]++;
			a[i]>>=1;
			++xx;
		}
		aa=max(aa,xx);
	}
	//cout<<aa-1<<endl;
	/*if(okb){
		int ans=0;
		int sum=0;
		for(int i=n;i>=n-m+1;--i) {
			sum|=a[i];
			//x=sum&j;
			ans=ans+a[i]&sum;//-a[i]&ans;
		}
		cout<<ans<<endl;
		return 0;
	}*/
	if(okb){
		int xx1=1,aa1=0;
	for(int i=1;i<=n-m+1;++i){
		xx1=1;
		while(a[i]){
			if(a[i]&1) c[xx1]++;
			a[i]>>=1;
			++xx1;
		}
		aa1=max(aa1,xx1);
	}
	int ans=0;
		int sum=0;
		int y=1;
		for(int i=1;i<=aa1;++i){
			if(c[i]>=2) ans+=y;
			y*=2; 
		} 
		cout<<ans<<endl;
		return 0;
	}
	if(n==m){
		int ans=0;
		int sum=0;
		int y=1;
		for(int i=1;i<=aa;++i){
			if(c[i]>=2) ans+=y;
			y*=2; 
		} 
		cout<<ans<<endl;
		return 0;
	}
	/*if(n==m){
		int ans=0;
		int sum=0;
		for(int i=2;i<=n;++i){
			sum|=a[i];
			//x=sum&j;
			ans=ans+a[i]&sum;
			//ans=ans&a[i];
		} 
		cout<<ans<<endl;
		return 0;
	}*/
	int max_=0,x=0,ans=0;
	for(int i=1;i<(1<<n);++i){
		int cnt=0;
		for(int j=1;j<=n;++j){
			int xx2=1,aa2=0;
			if((1<<j)&1){
				xx2=1;
		        while(a[j]){
			        if(a[j]&1) c[xx2]++;
			        a[j]>>=1;
			        ++xx2;
		        }
		        aa2=max(aa2,xx2);
				cnt++;
			}
			ans=0;
		    int y=1;
		    for(int i=1;i<=aa2;++i){
			    if(c[i]>=2) ans+=y;
			    y*=2; 
		    } 
		}
		if(cnt==m)max_=max(ans,max_);
	}
	cout<<max_<<endl;
	return 0;
}
//n<=20
//A
//max ai<4
//m=1=2=n-1=n 
/*4 2
2 3 15 12 12
*/
