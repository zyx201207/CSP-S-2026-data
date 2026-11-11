#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int> mp;
long long n,m;
long long a[500010];
long long ans=-1e9;
int check(int x){
	int cnt=mp[a[x]],sum=0;
	for(int i=x-1;i>=1;i--){
		if(a[x]==a[i]) continue;
		if(sum+(a[x]-a[i])<=m){
			cnt++;
			sum+=a[x]-a[i];
		}
		else{
			break;
		}
	}
	return cnt;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mp[a[i]]++;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(ans<check(i)){
			ans=check(i);
		}
	}
	cout<<ans;
	return 0;
} 
