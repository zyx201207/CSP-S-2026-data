#include<bits/stdc++.h>
using namespace std;
const int N=5e5+3;
long long n,m,a[N],ans=0,pre[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1&&m==1){
		cout<<1;
		return 0;
	}
	sort(a+1,a+n+1);
	long long cnt=1;
	for(int i=1,j=2;i<=n;j++){
		long long b=m;
		while(a[j]-a[i]<=b&&j<=n&&cnt<=n){
			b-=a[j]-a[i];
			cnt++;
			if(b<=0) break;
			j++;
		}
		i++;
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}