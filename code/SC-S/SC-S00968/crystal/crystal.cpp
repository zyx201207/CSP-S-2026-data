#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,k;
int a[N],s[N];
bool check(int x){
	int f=a[x]-s[x];
	return f<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
//	s[1]=a[1];
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
		a[i]=a[i]*i;
	}
	int l=1,r=n,mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(!check(mid)) r=mid-1;
		else{
			l=mid+1;
			k=max(k,mid);
		}
	}
	cout<<k<<endl;
	return 0;
}