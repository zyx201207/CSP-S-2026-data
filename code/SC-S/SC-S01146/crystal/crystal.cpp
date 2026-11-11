#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],sum,ans,x,f,l,maxn=-1e12,cha,flag;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",a+i),maxn=max(maxn,abs(a[i]));
	}
	if(n==1){
		cout<<1;
		return 0;
	}
	if(2*maxn*n<=m){
		cout<<n;
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(i==2)cha=a[2]-a[1];
		if(i>2){
			if(a[i]-a[i-1]!=cha)flag=1;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=x)x=a[i],f=1;
		else f++;
		l=max(l,f);
	}
	if(n>1e4){
		if(flag){
			for(int i=2;i<=n;i++){
				ans++;
				if(a[i]==a[i-1])continue;
				int c=a[i]-a[i-1];
				sum+=c*ans;
				if(sum>m){
					cout<<max(l,ans);
					return 0;
				}
			}
		}
		while((a[1]+a[ans])*ans<=2*m)ans++;
		cout<<max(l,ans);
		return 0;
	}
	for(int _=2;_<n;_++){
		for(int i=_;i<=n;i++){
			ans++;
			if(a[i]==a[i-1])continue;
			int c=a[i]-a[i-1];
			sum+=c*ans;
			if(sum>m){
				l=max(l,ans);
				break;
			}
		}
		ans=0;
	}
	cout<<n;
	return 0;
}