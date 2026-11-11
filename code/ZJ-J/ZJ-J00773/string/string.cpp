#include<bits/stdc++.h>
#define I_don_t_want_to_AFO int main()
#define I_want_to_study_OI_forever return 0;
using namespace std;
int n;
long long ans=0;
long long a[200005];
char c[200005];
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
	}
	int l=1,r=n;
	while(l<r){
		if(c[l]==c[r]){
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;	
			}else if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
			}else if(a[l]==a[r]){
				l++,r--;
			}
		}else{
			if(a[l]>a[r]){
				ans+=a[r];
				a[l]-=a[r];
				r--;	
			}else if(a[l]<a[r]){
				ans+=a[l];
				a[r]-=a[l];
				
				l++;
			}else if(a[l]==a[r]){
				ans+=a[l];
				l++,r--;
			}
		}
	}
	cout<<ans;
}
I_don_t_want_to_AFO{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int _=1;
//	cin>>_;
	while(_--){
		solve();
	}
	I_want_to_study_OI_forever
}
