#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],pre,ans=1,now=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(long long i=2;i<=n;i++){
		pre+=(a[i]-a[i-1])*(i-now);
		while(pre>m){
			pre-=(a[i]-a[now]);
			now++;
		}
		ans=max(ans,i-now+1);
	}
	cout<<ans;
}
