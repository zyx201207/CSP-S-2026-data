#include<bits/stdc++.h>
#define LL long long
#define For(i,a,b)	for(int i=a;i<=b;i++)
#define Rep(i,a,b)	for(int i=a;i>=b;i--)
using namespace std;
const int N=5e5+5;
int n,ans;
LL m,a[N],s[N];
bool check(int l,int r){
	int cnt=r-l;
	if(cnt*a[r]-(s[l]-s[r])>m)	return false;
	return true;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	For(i,1,n){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	Rep(i,n,1)	s[i]=s[i+1]+a[i];
	For(i,1,n){
		int l=0,r=i-1,res=0;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(i-mid,i)){
				res=mid;
				l=mid+1;
			}else{
				r=mid-1;
			}
		}
		ans=max(ans,res);
	}
	cout<<ans+1;
	return 0;
}