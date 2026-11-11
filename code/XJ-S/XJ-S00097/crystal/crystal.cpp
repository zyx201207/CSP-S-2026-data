#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[500005],cf[500005],cnt,sum=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m,sum;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		cf[i]=cf[i-1]+a[i];
	} 
	ll minin=0x3f3f3f3f3f3f;
	ll d=0;
	for(int i=1;i<=n;i++){
		cnt=(a[i]*i-cf[i])+((cf[n]-cf[i-1])-a[i]*(n-i+1));
		if(minin>cnt){
			d=i;
			minin=cnt;
		}
	}
	int l=d-1,r=d+1;
	while(m>0&&l>=1&&r<=n){
		if(l>1&&r<n){
			ll minn=min(a[d]-a[l],a[r]-a[d]);		
			if(m>minn){
				if(a[d]-a[l]>a[r]-a[d]){
					r++;
				}else{
					l--;
				}
				sum++;
				m=m-minn;
			}
		}
		if(l==1){
			ll minn=a[r]-a[d];		
			if(m>minn){
				r++;
				sum++;
				m=m-minn;
			}
		}	
		if(r==n){
			ll minn=a[d]-a[l];		
			if(m>minn){
				l--;
				sum++;
				m=m-minn;
			}
		}
	}
	cout<<sum;
	return 0;
}

