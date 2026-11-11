#include<bits/stdc++.h>
using namespace std;int n;long long m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;int a[500002];
	for(int i=1;i<=n;i++)cin>>a[i];
	bool b=1;
	for(int i=3;i<=n;i++){
		b=((a[n]-a[n-1])==(a[2]-a[1]));
		if(!b)break;
	}
	if(b){
		int i=1;
		while(m-i>=0&&i<=n-1)m-=i,i++;
		if(i<=n-1)cout<<i;
		else if(m%n==0)cout<<n;
		else cout<<n-1;
		return 0;
	}
	sort(a+1,a+n+1);int ans=1;
	for(int i=n;i>1;i--){
		if(ans>=i)break;
		int num=m,j;
		for(j=i-1;j>0;j--){
			if(num>=a[i]-a[j])num-=(a[i]-a[j]);
			else break;
		}
		if(i==n){
			if(!m%(i-j))ans=max(ans,i-j);
		}else ans=max(ans,i-j);
	}
	cout<<ans;
	return 0;
}