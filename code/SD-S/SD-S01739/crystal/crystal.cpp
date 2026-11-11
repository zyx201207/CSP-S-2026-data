#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans,sum,cnt;  
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	sum=m;
	for(int i=0;i<n;i++){
		sum+=a[i];
		while(sum<(i-cnt+1)*a[i]){
			cnt++;
			sum-=a[cnt];
		}
		ans=max(ans,i-cnt+1);
	}
	cout<<ans;
	return 0;
}

