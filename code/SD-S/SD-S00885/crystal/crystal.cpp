#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5; 
int n,m;
int a[N];
int ans=-2147483648;
void dfs(int k,int mmax,int dif,int idx){
	if(dif>m){
		ans=max(ans,k-1);
		return;
	}
	if(idx>=n){
		ans=max(ans,k);
		return;
	} 
	for(int i=idx+1;i<=n;i++){
		if(k==0){
			dfs(k+1,a[i],0,i);
		}else if(a[i]){
			dfs(k+1,mmax,dif+(mmax-a[i]),i);
		}
	}
}
int speci(){
	int diff=0,cnt=0;
	for(int i=n;i>=1;i--){
		if(diff>m){
			cnt--;
			return cnt;
		}
		diff+=(a[n]-a[i]);
		cnt++;
	}
	return cnt;
}
bool spe=true;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int cha=a[2]-a[1];
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=cha){
			spe=false;
			break;
		}
	}
	if(spe==true){
		cout<<speci();
		return 0;
	}
	sort(a+1,a+n+1,greater<int>());
	dfs(0,-2147483648,0,0);
	cout<<ans;
	return 0;
}
