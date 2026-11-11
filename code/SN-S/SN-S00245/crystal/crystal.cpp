#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL a[100005],b[100005],c[100005],d[100005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	LL n,m;
	cin>>n>>m;
	for(LL i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(LL i=1;i<=n-1;i++){
		b[i]=a[i+1]-a[i];
	}
	LL ans=0,ans1=0,ans2=0,ret=0;	
	if(n%2==0){
		LL mid1=a[n/2];
		LL mid2=a[n/2+1];
		//算中间数 
		for(LL i=1;i<=n;i++){
			if(a[i]>mid1)b[i]=a[i]-mid1;
			else b[i]=mid1-a[i];
		}
		sort(b+1,b+n+1);
		//算各数与mid1的差 
		for(LL i=1;i<=n;i++){
			if(a[i]>mid2)c[i]=a[i]-mid2;
			else c[i]=mid2-a[i];
		}
		sort(c+1,c+n+1); 
		//算各数与mid2的差 
		for(LL i=1;i<=n;i++){
			ret+=b[i];
			ans++;
			if(ret>m)break;
			else if(ret==m)break;
			else continue;	
		}
		//算ans 
		ret=0;
		for(LL i=1;i<=n;i++){
			ret+=c[i];
			ans1++;
			if(ret>m)break;
			else if(ret==m)break;
			else continue;
		}
		//算ans1 
		cout<<max(ans,ans1);
		return 0;
	}
	else{
		LL mid=a[n/2+1];
		for(LL i=1;i<=n;i++){
			if(mid>a[i])d[i]=mid-a[i];
			else d[i]=a[i]-mid;
		}
		sort(d+1,d+n+1);
		//算各数与mid的差 
		ret=0;
		for(LL i=1;i<=n;i++){
			ret+=d[i];
			ans2++;
			if(ret>m)break;
			else if(ret==m)break;
			else continue;
		}
		//算ans2 
		cout<<ans2;
		return 0;
	}
	return 0;
}
