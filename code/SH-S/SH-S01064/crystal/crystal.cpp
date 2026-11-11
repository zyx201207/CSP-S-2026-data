#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
int n;
long long m,a[MAXN];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	bool flga=true,flgb=true;
	int k=0;
	for(int i=1;i<=n;i++){
		if(a[i]!=i) flga=false;
		if(i==2) k=a[2]-a[1];
		else if(i>2)
			if(a[i]-a[i-1]!=k) flgb=false;
	}
	int ans=1;
	if(flga){
		for(int i=n;i>1;i--){
			long long sum;
			if(i%2==0) sum=i/2*(i-1);
			else sum=(i-1)/2*i;
			if(sum<=m){
				ans=i;
				break;
			}
		}
	}
	else if(flgb){
		for(int i=n;i>1;i--){
			long long sum;
			if(i%2==0) sum=i/2*(i-1)*k;
			else sum=(i-1)/2*i*k;
			if(sum<=m){
				ans=i;
				break;
			}
		}
	}
	else{
		sort(a+1,a+n+1);
		for(int i=n;i>0;i--){
			long long sum=m;
			int cnt=1;
			for(int j=i-1;j>0;j--){
				long long c=a[i]-a[j];
				if(sum<c) break;
				sum-=c;
				cnt++;
			}
			ans=max(ans,cnt);
		}
	}
	cout<<ans;
	return 0;
}
