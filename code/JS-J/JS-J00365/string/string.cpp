#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N=2e5+34;
ll n,a[N],sum,ans;
ll b[N];
char c[N],cc[N];

int main(){
	freopen("string.in","r",stdin);	
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	
	ll bian=sum/2;
	ll mid=(sum+1)/2;
	ll t=0,l,r;
	sum=0;
	bool f=1;
	for(int i=1;i<=n;i++){
		sum+=a[i];
		if(f&&sum>mid){
			b[++t]=bian-sum+a[i];
			cc[t]=c[i];
			l=t;
			b[++t]=sum-mid;
			cc[t]=c[i];
			r=t;
			f=0;
			
		}else if(f&&sum==mid){
			f=0;
			b[++t]=a[i];
			cc[t]=c[i];
			l=t;
			r=t+1;
		}else{
			b[++t]=a[i];
			cc[t]=c[i];
		}
	}
	
	while(l>=1&&r<=t){
		if(cc[l]==cc[r]){
			if(b[l]>b[r]){
				b[l]-=b[r];
				r++;
			}else if(b[l]==b[r]){
				b[l]=b[r]=0;
				l--,r++;
			}else{
				b[r]-=b[l];
				l--;
			}
		}else{
			if(b[l]>b[r]){
				ans+=b[r];
				b[l]-=b[r];
				r++;
			}else if(b[l]==b[r]){
				ans+=b[l];
				b[l]=b[r]=0;
				l--,r++;
			}else{
				ans+=b[l];
				b[r]-=b[l];
				l--;
			}
		}
	}
	cout<<ans;
	return 0;
}









