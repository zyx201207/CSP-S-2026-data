#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll a[N],b[N];
int n,m;
int f[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	int j=1;
	f[1]=1;
	b[1]=0;
	for(int i=2;i<=n;i++){
		ll sum=1ll*f[i-1]*(a[i]-a[i-1])+b[i-1];
		f[i]=f[i-1]+1;
		
		if(sum<=m){
			b[i]=sum;
			continue;
		}
		while(sum>m&&j<i){
			int tmp=a[i]-a[j];
			sum-=tmp;
			j++;
			f[i]--;
		}
		b[i]=sum;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
	//	cout<<a[i]<<"   f: "<<f[i]<<" b:"<<b[i]<<endl;
		ans=max(ans,f[i]);
	}
	printf("%d\n",ans);
	return 0;
} 
