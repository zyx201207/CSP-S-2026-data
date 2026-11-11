#include <bits/stdc++.h>

using namespace std;
long long a[2000005];
int n,d;
int mn(int l,int r){
	int idx=l;
	if(a[r]-a[l]<=d){
		return -1;
	}
	int stp=0;
	int la=a[l];
	while(idx<=r){
		if(la+d>=a[idx]&&la+d<a[idx+1]){
			la=a[idx];
			stp++;
		}
		idx++;
	}
	return stp;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int c,t;
	cin>>c>>t;
	long long ans=0;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int l=1;l<=n;l++){
			for(int r=l+3;r<=n;r++){
				int ste=mn(l,r);
				if(ste==-1)continue;
				else{
					if(r-l+1-ste<=ste){
						ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
