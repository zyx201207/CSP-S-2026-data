#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005],c[500005],sum[500005],ans2,ans,k;
bool check2(int l,int r){
	long long ccc=0;
	for(int i=l;i<=r;i++){
		ccc+=a[r]-a[i];
		if(ccc>m)return 0;
	}
	return 1;
}
bool check(int mid){
	long long kkk=0,mi=mid+1;
	int L=1,R=mid,mid2;
	while(L<=R){
		mid2=(L+R)/2;
		if(check2(mid2,mid)==1)R=mid2-1,mi=mid2;
		else L=mid2+1;
	}
	kkk=mid-mi+1;
	if(kkk>ans){
		ans=kkk;
		return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int ok=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==2)k=a[2]-a[1];
		if(i!=1&&a[i]-a[i-1]!=k)ok=0;
	}
	sort(a+1,a+n+1);
	if(n<=5000){
		for(int i=1;i<=n;i++)check(i);
		cout<<ans;
		return 0;
	}
	if(ok==1){
		long long www=0;
		for(int i=1;i<=n;i++){
			www+=i*k;
			if(www>m){
				cout<<i<<endl;
				return 0;
			}
		}
		cout<<n<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++)
		if(sum[i]+m>=a[i]*i)ans2=i;
	int l=1,r=n,mid;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid)==1)l=mid+1;
		else r=mid-1;
	}
	cout<<max(ans,ans2);
	return 0;
}
