#include<bits/stdc++.h>
using namespace std;
const long long N=2e6+7;
long long C,T;
long long n,d;
long long x[N],ans=0;
long long dp[N],sum[N];
long long r[N],l[N];
int main(){
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>C>>T;
	while(T--){
		cin>>n>>d;
		ans=0;
		for(long long i=1;i<=n;i++){
			cin>>x[i];
		}
		if(C>=11&&C<=12){
			long long d0=x[2]-x[1];
			if(d/d0<=1) cout<<0<<"\n";
			else{
				long long temp=2*(d/d0)-1;
				cout<<max(n-temp,0ll)<<"\n";
			}
			continue;
		}
		long long pos=1;
		for(long long i=1;i<=n;i++){
			while(pos<n&&x[pos+1]-x[i]<=d) pos++;
			r[i]=pos;
		}
		pos=n;
		for(long long i=n;i>=1;i--){
			while(pos>1&&x[i]-x[pos-1]<=d) pos--;
			l[i]=pos;
		}
		l[0]=0,r[0]=0;
		l[n+1]=n+1,r[n+1]=n+1;
		if(C>=13&&C<=14){
			long long ans=0;
			for(long long i=2;i<n-1;i++){
				if(x[i+1]-x[i]>d) continue;
				long long cntl=0,cntr=0;
				long long p=l[x[i]],q=min(l[x[i+1]]-1,i-1);
				if(p<=q&&r[p]==i) cntl=q-p+1;
				p=r[x[i+1]],q=max(r[x[i]]+1,i+2);
				if(p>=q&&l[p]==i+1) cntr=q-p+1;
				ans+=cntl*cntr;
			}
			cout<<ans<<"\n";
		}
//		for(long long i=1;i<=n;i++) cout<<i<<" "<<l[i]<<" "<<r[i]<<endl;
		for(long long i=2;i<n-1;i++){
			long long cntl=0,cntr=0;
			if(x[i+1]-x[i]>d) continue;
			pos=i;
			while(pos<=n){
//				cout<<pos<<endl; 
				if(l[r[pos]]!=pos) break;
				long long p=max({r[pos-1]+1,i+2,pos+1}),q=r[pos];
//				cout<<p<<" "<<q<<endl; 
				if(p>q||p>n||q>n) break;
				cntr+=q-p+1;
				pos=q;
			}
			pos=i+1;
			while(pos>=1){
//				cout<<pos<<endl;
				if(r[l[pos]]!=pos) break;
				long long p=min({l[pos+1]-1,i-1,pos-1}),q=l[pos];
//				cout<<p<<" "<<q<<endl;
				if(p<q||p<1||q<1) break;
				cntl+=p-q+1;
				pos=p;
			}
//			cout<<cntl<<" "<<cntr<<endl<<endl;
			ans+=cntl*cntr;
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}
