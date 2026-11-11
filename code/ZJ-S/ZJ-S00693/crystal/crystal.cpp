#include<bits/stdc++.h>
using namespace std;
int n,ans,L=1,R=1;
long long m,cnt,num;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	while(R<=n){
		cnt+=(a[R]-num)*(R-L);
		num=a[R];
		while(cnt>m){
			cnt-=(a[R]-a[L]);
			L++;
		}
		ans=max(ans,R-L+1);
		R++;
	}
	cout<<ans;
	return 0;
}