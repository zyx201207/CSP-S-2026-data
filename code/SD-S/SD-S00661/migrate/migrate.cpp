#include<bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
const int N=2e6+10;
int a[N],x1[N],x2[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll c,t;
	cin>>c>>t;
	while(t--){
		memset(a,0,sizeof a);
		ll n,d,tt=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		ll l=1,r=d+2;
		while(r<=n){
			ll p1=0;
			memset(x1,0,sizeof x1);
			memset(x2,0,sizeof x2);
			ll as=a[l],ans=0;
					while(as<a[r]&&a[r]-a[r-1]<=d){
						for(int z=r;z>=l;z--){
							if(a[z]<=as+d){
								ans++;
								x1[++p1]=as;
								as=a[z];
								break;
							}
						}
					}
					x1[++p1]=as;
			ll bx=a[r],sum=0,p2=p1+1;
			while(bx>a[l]&&a[r]-a[r-1]<=d){
				for(int z=l;z<=r;z++){
					if(a[z]>=bx-d){
						sum++;
						x2[--p2]=bx;
						bx=a[z];
						break;
					}
				}
			}
			x2[--p2]=bx;
			bool k=1;
			for(int o=1;o<=p1;o++){
				if(x1[o]!=x2[o]) k=0;
	    	}
		 	if(k==0&&(r-1)%2!=0&&a[r]-a[r-1]<=d){
				if(ans==sum){
				tt++;
				if(a[r+1]-a[r]<=d)
				tt+=(n-r);
			}
			}
			r++;
		}
		cout<<tt<<endl;
	}
	return 0;
}
