#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+5;
long long a[N],sum[N];
long long n,m;
int answer(int i){
	long long cnt=0,limit=0;
	for(int j=i-1;j>=1;j--){
		if(limit+a[i]-a[j]<=m){
			limit+=a[i]-a[j];
			cnt++;
		}else{
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
	}
	sort(a+1,a+1+n);
	int ans=1;
	for(int i=2;i<=n;i++){
		while(a[i]==a[i+1]) i++;
		ans=max(ans,answer(i)+1);
	}
	cout<<ans;
} 