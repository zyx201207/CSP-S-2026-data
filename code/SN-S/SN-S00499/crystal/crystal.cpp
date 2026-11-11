//左献科 西安市铁一中学 SN-S00499 
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],sum[500005],maxn=0;
bool check(int l,int r){
	int x=a[r+1]*(r-l+1)-(sum[r]-sum[l-1]);
//	cout<<"check"<<l<<' '<<r<<' '<<x<<' '<<(x<=m)<<endl;
	return x <=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=i+1,r=n-1;
		while(l<r){
			int mid=(l+r+1)/2;	
			if(check(i,mid)){
				l=mid;
			}else{
				r=mid-1;
			}
		}
//		cout<<i<<' '<<l<<endl;
		maxn=max(maxn,l-i+2);
	}
	cout<<maxn;
}

