#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500010],b[500010];
signed solve1(){
	int d=b[2],cnt=1;
	while(m>=0){
		m-=cnt*d;
		if(m<0||cnt==n) break;
		cnt++;
	}
	return cnt;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int flag=1;
	for(int i=2;i<=n;i++){
		b[i]=a[i]-a[i-1];
		if(i>=3&&b[i]!=b[i-1]) flag=0;
	} 
	if(flag==1){
		cout<<solve1();
		return 0;
	} 
	int ans=0;
	for(int h=1;h<=n;h++){
		int q=0;
		for(int i=h;i<=n;i++) q+=a[n]-a[i]; 
		for(int i=n;i>=h;i--){
			if(m>=q){
				ans=max(ans,i-h+1);
				break;
			} 
			q-=(i-h+1)*b[i];
		}
	}
	cout<<ans;
	return 0;
}
