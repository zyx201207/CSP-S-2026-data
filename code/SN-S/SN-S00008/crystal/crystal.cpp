#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[100050];
long long s[100050];
long long nowmax=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	int l=n;
	
	for(int r=n;l>=1;r--){
		if(l>r)l=r;
		int v=a[r]*(r-l+1)-(s[r]-s[l-1]);
		while(v+a[r]-a[l-1]<=m){
			l--;
			v=v+a[r]-a[l];
			nowmax=max(nowmax,1LL*(r-l+1));
			if(l<=0)break;
		}
	}
	cout<<nowmax;
	return 0;
}
