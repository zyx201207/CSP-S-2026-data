#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int bit(int k){
	int cnt=0;
	while(k){
		if(k%2==1)cnt++;
		k/=2;
	}
	return cnt;
}
int n,m,a[N],ans;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	if(n<=2000){
		if(n<=20){
			for(int i=1;i<(1<<n)-1;i++){
				int k1=bit(i);
				if(k1==m){
					int ans1=-1,i1=i;
					for(int j=0;j<n;j++){
						if(i1%2==1){
							if(ans1==-1) ans1=a[j];
							else ans1=ans1&a[j];
						}
						i1/=2;
					}
					ans=max(ans,ans1);
				}
			}
			cout<<ans;
			return 0;
		}
		if(m==1){
			sort(a,a+n);
			cout<<a[n-1];
			return 0;
		}
		if(n==m){
			ans=a[0];
			for(int i=1;i<n;i++){
				ans&=a[i];
			}
			cout<<ans;
			return 0; 
		}
		if(m==2){
			for(int i=0;i<n;i++){
				for(int j=i+1;j<n;j++){
					ans=max(ans,a[i]&a[j]);
				}
			}
			cout<<ans;
			return 0;
		}
	}else{
		sort(a,a+n);
		cout<<a[n-m];
	}
	return 0;
}
