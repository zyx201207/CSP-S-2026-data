#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans=1,sum,cnt=1;
bool flag1=1,flag2=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i) flag1=0;
	}
	if(flag1==1){
		for(int i=1;i<=n;i++){
			sum+=i;
			if(sum>m) break;
			else ans++;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		sum+=(i-cnt)*(abs(a[i]-a[i-1]));
		while(sum>m){
			sum-=a[i]-a[cnt];
			cnt++;
		}
		ans=max(ans,i-cnt+1);
	}
	cout<<ans;
	return 0;
}
