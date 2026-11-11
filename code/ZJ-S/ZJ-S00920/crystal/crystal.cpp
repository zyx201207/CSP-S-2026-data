#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,ans,t,l,r,mid;
ll a[500010],s[500010],ss[500010],x[500010],sum,cnt,m;
bool cmp(int a,int b){
	return a<b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<n;i++) x[i]=a[i+1]-a[i],s[i]=x[i];
	for(int i=n-1;i>=1;i--) sum+=i*x[i],s[i]+=s[i+1],ss[i]=s[i];
	for(int i=2;i<n;i++) ss[i]+=ss[i-1];
	a[n+1]=a[n];
	for(int i=n;i>=1;i--){
		sum-=i*x[i];
		cnt+=a[i+1]-a[i];
		l=1,r=i;
		t=i;
		while(l<=r){
			mid=(l+r)>>1;
			if(sum-ss[mid-1]+cnt*(mid-1)<=m){
				t=mid;
				r=mid-1;
			}else l=mid+1;
		}
		t=i-t+1;
		ans=max(ans,t);
	}
	cout<<ans<<endl;
	return 0;
}
