#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
using ll=long long;
const int N=5e5+5;
int n,m;ll a[N],f[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);for(int i=1;i<=n;i++)f[i]=f[i-1]+a[i];
	int ans=1;
	for(int i=1;i<=n;i++){
		int l=1,r=i,res=i;
		while(l<=r){
			int mid=(l+r)>>1;
			if((i-mid+1)*a[i]-(f[i]-f[mid-1])<=m)res=mid,r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,i-res+1);
	}
	cout<<ans<<endl;
	return 0;
}
//last remote
//这么快就5年了
//whk很有趣
//灵梦fumo很fumo 
