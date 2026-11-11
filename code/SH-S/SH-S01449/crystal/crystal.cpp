#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],M;
long long check(long long mid){
	long long cnt=0;
	for(int i=1;i<=n;i++){
		if(mid-a[i]<0) continue;
		if(mid-a[i]<=M){
			cnt++;
		}else break;
		m=m-(mid-a[i]);
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
	sort(a+1,a+n+1);
	bool flag=1;
	for(int i=2;i<=n;i++){
		if(a[i]!=a[i-1]){
			flag=0;
			break;
		}
	}
	if(flag){
		cout<<n<<endl;
		return 0;
	}
	long long l=1,r=1e18+1e12,ans=1;
	while(l<r){
		long long mid=l+r>>1;
		M=m;
		if(check(mid)){
			ans=max(check(mid),ans);
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
