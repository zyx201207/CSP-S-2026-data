#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5+5;
ll n,m,pre[N];
int ans;
ll x[N];
bool check(ll num){
	int k = m,cnt=0;
	for(int i = n;i>=1;i--){
		if(x[i]<=num){
			if(m-(num-x[i])<0) break;
			else m-=(num-x[i]),cnt++;
		}
	}
	if(cnt>=ans){
		ans=cnt;
		return true;
	}else return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>x[i];
	}
	sort(x+1,x+1+n);
	for(int i = 1;i<=n;i++){
		pre[i] = pre[i-1]+x[i];
		int l = 1,r = i;
		while(l<=r){
			int mid=(l+r)/2;
			if(pre[i]-pre[mid-1]+m>=x[i]*(i-mid+1)){
				ans=max(ans,i-mid+1);
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
	fclose(stdin);
	fclose(stdout);
	
} 
