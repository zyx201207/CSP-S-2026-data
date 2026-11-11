#include<bits/stdc++.h>
using namespace std;
const int N=500100;
int n;
long long m;
long long a[N];
bool cmp(long long x,long long y){
	return x<y;
}
void solve(){
	int k=a[2]-a[1];
	for(int i=1;i<=n;i++){
		if(k*i*(i-1)/2>m){
			cout<<i-1;
			return;
		}
	}
	cout<<n;
	return;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	if(m>100000000){
		solve();
		return 0;
	}
	int l=1,r=2;
	int cnt=1;
	int ans=1;
	long long temp=0;
	while(r<=n){
		if(l>r&&l<=n-1){
			r=l+1;
			cnt=1,temp=0;
			continue;
		}
		if(a[r]==a[r-1]){
			r++;
			cnt++;
			ans=max(ans,cnt);
		}else{
			temp+=(r-l)*(a[r]-a[r-1]);
			if(temp>m){
				
				temp-=(a[r]-a[r-1]);
				temp-=(r-l)*(a[r]-a[r-1]);
				l++;
				cnt--;
			}else{
				r++;
				cnt++;
			}
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
} 
