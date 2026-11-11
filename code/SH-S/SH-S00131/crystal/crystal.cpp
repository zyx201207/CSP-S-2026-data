#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+9;
int n,ans;
ll m,a[N],sum[N];
int cal(int x,int la){
	ll s=sum[la]-sum[x-1];
	s=(la-x+1)*a[la]-s;
	return s;
}
void solve(){
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];		
	}
	/*for(int i=1;i<=n;i++){
		cout<<sum[i]<<" ";
	}
	cout<<endl;*/
	for(int i=2;i<=n;i++){
		int cnt=0;
		int l=1;
		int r=i;
		cnt=i;
		while(l!=r){
			int mid=(l+r)/2;
			ll ne=cal(mid,i);
			//cout<<l<<" "<<r<<" "<<mid<<" "<<ne<<endl;
			if(ne<m){
				r=mid;
			}
			else if(ne==m){
				cnt=(i-mid+1);
				break;
			}
			else{
				if(cal(mid+1,i)<=m){
					cnt=(i-mid);
					break;
				}
				else{
					l=mid+1;
				}
			}
		}
		//cout<<cnt<<endl;
		ans=max(ans,cnt);
	}
	cout<<ans<<endl;
	return;
}
void solve_BF(){
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		int cnt=0;
		for(int j=i-1;j>=1;j--){
			int ne=a[i]-a[j];
			cnt+=ne;
			//cout<<ne<<" "<<cnt<<endl;			
			if(cnt==m){
				ans=max(ans,i-j+1);
				break;
			}
			else if(cnt>m){
				ans=max(ans,i-j);
				break;
			}
		}
		if(cnt<m){
			ans=max(ans,i);
		}
		/*cout<<cnt<<" "<<ans<<endl;
		cout<<endl;*/
	}
	cout<<ans<<endl;
	return;	
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(n<=5000){
		solve_BF();
	}
	else{
		solve();	
	}
	return 0;
}
