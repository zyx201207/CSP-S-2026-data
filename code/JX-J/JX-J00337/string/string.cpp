#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2*1e5+200;
int t;
ll a[N];
ll ans;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=t;
	while(l<r){
		if(c[l]==c[r]){
			if(a[l]==a[r]){
				l++,r--;
				continue;
			}
			if(a[l]>a[r]){
			    while(a[l]>a[r]){
					if(c[l]!=c[r]){
						ans+=min(a[l],a[r]);
					}
					a[l]-=a[r];
					r--;
				}
			}else if(a[l]<a[r]){
				while(a[l]<a[r]){
					if(c[l]!=c[r]){
						ans+=min(a[l],a[r]);
					}
					a[r]-=a[l];
					l++;
				}
			}
		}else{
			if(a[l]==a[r]){
				ans+=a[l];
				l++,r--;
				continue;
			}
			if(a[l]<a[r]){
				while(a[l]<a[r]){
					if(c[l]!=c[r]){
						ans+=min(a[l],a[r]);
					}
					a[r]-=a[l];
					l++;
				}
			}
			else if(a[l]>a[r]){
				while(a[l]>a[r]){
					if(c[l]!=c[r]){
						ans+=min(a[l],a[r]);
					}
					a[l]-=a[r];
					r--;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}

