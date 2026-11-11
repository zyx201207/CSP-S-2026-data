#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],s[500005],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,r=2,sum=0;
	bool flag=0,dc=0,ai=0;
	int k=1;
	for(int i=1;i<n-1;i++){
		if(a[i+1]-a[i]!=a[i+2]-a[i+1]) {
			dc=1;break;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=i){
			ai=1;break;
		}
	}
	if(dc==0||ai==0){
		r=1;
		while(r<=n){
			r++;
			for(int i=1;i<r;i++){
				//cout<<i<<" "<<r<<"\n";
				//cout<<"sum="<<sum<<"\n";
				if((a[i]>=0&&a[r]>=0)||(a[i]<0&&a[r]<0)) sum+=abs(abs(a[r])-abs(a[i]));
				else sum+=a[r]-a[i];
				//cout<<"sum="<<sum<<"\n";
				if(sum>m){
					cout<<r-1;
					return 0;
				}
			}
		}
	}
	while(l>0&&r<=n&&l<=r){
		//cout<<k<<":\n";
		sum=0,flag=0;
		for(int i=l;i<r;i++){
			//cout<<i<<" "<<r<<"\n";
			//cout<<"sum="<<sum<<"\n";
			if((a[i]>=0&&a[r]>=0)||(a[i]<0&&a[r]<0)) sum+=abs(abs(a[r])-abs(a[i]));
			else sum+=a[r]-a[i];
			//cout<<"sum="<<sum<<"\n";
			if(sum>m){
				l++,r++;
				flag=1;
				break;
			}
		}
		if(flag==1) continue;
		ans=max(ans,r-l+1);
		//cout<<l<<" "<<r<<"\n";
		r++;
	}
	cout<<ans;
} 
