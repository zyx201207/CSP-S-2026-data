#include<bits/stdc++.h>
using namespace std;
long long a[500010];
long long b[500010];
long long c[500010];
bool cmp(long long a,long long b){
	return a<b;
}


int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	int ans=-1e9,cnt=0,wz=0;
	for(int i=1;i<=n;i++){
		b[i]=a[i]-a[i-1];
	//	b[i]=abs(b[i]);
		c[i]=b[i]*(i-1-wz);
		c[i]+=c[i-1];
		if(c[i]>=m)c[i]=0,c[i-1]=0,ans=max(ans,cnt),cnt=0,wz=i-1,i--;
		else cnt++;
	//	cout<<i;
	}
	ans=max(cnt,ans);

	cout<<ans;
	return 0;
}