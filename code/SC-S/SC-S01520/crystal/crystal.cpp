#include<bits/stdc++.h>
using namespace std;
int n,ans,u,v;
long long j,m,a[500005],q[500005],o,p;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<25)p+=25-a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		o=i-1;
		q[i]=q[i-1]+o*(a[i]-a[i-1]);
		while(q[i]-q[j]-j*(a[i]-a[j])>m&&j<i)j++;
		if(ans<i-j)ans=i-j,u=i,v=j;
	}
	cout<<max(ans,1);
	return 0;
} 