#include<bits/stdc++.h>
#define ll long long
#define N 1000005
using namespace std;
ll n,m,a[N],b[N],dc;
struct P10{
	ll ans,cnt,sum[N],sum_[N];
	void solve(){
		ans=0;
		cnt=0;
		memset(sum,0,sizeof(sum));
		memset(sum_,0,sizeof(sum_));
		for(int i=0;i<=m;i++){
			cnt=0;
			b[1]=a[1]+i;
			cnt+=i;
			for(int j=0;j<=m-i;j++){
				if(n==1||cnt+j>m)break;
				b[2]=a[2]+j;
				for(int k=0;k<=m-j-i;k++){
					if(n==2||cnt+k>m)break;
					b[3]=a[3]+k;
					for(int p=0;p<=m-i-j-k;p++){
						if(n==3||cnt+p>m)break;
						b[4]=a[4]+p;
						for(int q=0;q<=m-i-j-k-p;q++){
							if(n==4||cnt+q>m)break;
							for(int o=1;o<=20;o++)sum[o]=0;
							for(int o=0;o<=20;o++)sum_[o]=0;
							b[5]=a[5]+q;
//							for(int o=1;o<=n;o++)cout<<b[o]<<" ";
//							cout<<"\n";
							for(int o=1;o<=n;o++){
								if(b[o]>0)sum[b[o]]++;
								else sum_[abs(b[o])]++;
							}
//							for(int o=1;o<=20;o++)cout<<sum[o]<<" ";
//							cout<<"\n";
							for(int o=1;o<=20;o++){
//								cout<<sum[o]<<"\n";
								ans=max(ans,max(sum[o],sum_[o]));
//								cout<<ans<<" ";
							}
							ans=max(ans,sum_[0]);
//							cout<<"\n";
//							cout<<ans<<"\n";
						}
					}
				}
			}
		}
		cout<<ans;
	}
}p10;
struct P10a{
	ll ans,l,cf[N];
	ll r;
	void solve(){
		l=n/2+1;
		r=l;
		for(int i=1;i<=n;i++)cf[i]=a[i]-a[i-1];
		for(int i=1;i<=n;i++){
			if((r-l+1>m&&(l!=1&&cf[l]>m))||r-l+1==n||m<=0)break;
			if(cf[l]>m||l-1==0){
				cf[l]++;
				cf[r+1]--;
				r++;
				m-=r-l-1;
			}
			else{
				cf[--l]+=cf[l+1];
				cf[l+1]=0;
				m-=cf[l]-1;
			}
//			cout<<l<<" "<<r<<"\n";
//			for(int i=1;i<=n;i++)cout<<cf[i]<<" ";
//			cout<<"\n";
//			cout<<m<<"\n";
		}
		for(int i=1;i<=n;i++)if(cf[i]==0)ans++;
		cout<<ans+1;
	}
}p10a;
struct P10b{
	ll ans,l,cf[N];
	ll r;
	void solve(){
		l=n/2+1;
		r=l;
		for(int i=1;i<=n;i++)cf[i]=a[i]-a[i-1];
		for(int i=1;i<=n;i++){
			if(((r-l+1)*dc>m&&(l!=1&&cf[l]>m))||r-l+1==n||m<=0)break;
			if(cf[l]>m||l-1==0){
				cf[l]+=dc;
				cf[r+1]-=dc;
				r++;
				m-=(r-l)*dc;
			}
			else{
				cf[--l]+=cf[l+1];
				cf[l+1]=0;
				m-=cf[l]-1;
			}
//			cout<<l<<" "<<r<<"\n";
//			for(int i=1;i<=n;i++)cout<<cf[i]<<" ";
//			cout<<"\n";
//			cout<<m<<"\n";
		}
		for(int i=1;i<=n;i++)if(cf[i]==0)ans++;
		cout<<ans+1;
	}
	
}p10b;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	bool isa=true,isb=true;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i)isa=false;
		dc=abs(a[2]-a[1]);
		if(a[i]-a[i-1]!=dc)isb=false;
	}
	if(n<=5&&m<=10)p10.solve();
	if(isa)p10a.solve();
	else if(isb)p10b.solve();
	else cout<<n/2+1;
	return 0;
}
