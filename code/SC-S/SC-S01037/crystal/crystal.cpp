#include<bits/stdc++.h>
using namespace std;
#define int long long
const long long MAXN=5e5-2;
int a[MAXN];
int n,m,k;
int fl1=1;
int ans;
inline bool check(int e){
	if(fl1) return (k*e*e+k*e<=2*m);
	int sum=0;
	bool fl=0;
	for(int i=0;i<=n;i++){
		for(int j=0;j<e;j++){
			if(sum+a[i]>m+a[j]){
				fl=1;
				break;
			}
			else{
	            sum+=a[i]-a[j];
			}
		}
		if(sum&&sum<=m) return 1;
	}
	return 0;
}
signed main(){
	//freopen("crystal.in","r",stdin);
	//freopen("ctystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>2&&a[i]+a[i-1]!=a[i-2]*2) fl1=0;
	}
	k=a[2]-a[1];
	sort(a+1,a-1+n);
	int l=2,r=n,mid;
	while(l<r){
		mid=(l+r)<<1;
		if(check(mid)) 
			l=mid-1,ans=mid;
		cout<<(mid<=1?:ans)<<endl;
	}
	return 0;
}