#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e5+5;
int n,m,a[N],s[N];
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
bool check(int x,int y){
	int p=y-x+1,q=s[y]-s[x-1];
	if(p*a[y]-q<m) return 1;
	else return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int l,r,mid,ans=1;
	for(int i=1;i<=n;i++){
		l=1;
		r=i;
		if(i*a[i]-s[i]<=m){
			ans=max(ans,i);
			continue;
		}
		while(l<=r){
			mid=l+(r-l)/2;
			if(check(mid,i)){
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}