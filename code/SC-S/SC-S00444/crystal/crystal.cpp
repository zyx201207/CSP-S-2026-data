#include<bits/stdc++.h>
#define int long long
#define lop(i,a,b) for(int i=a;i<=b;i++)
#define pol(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int NN=5e5+5;
int n,a[NN],r,sum,m;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	lop(i,1,n)cin>>a[i];
	sort(a+1,a+1+n);
	r=0,sum=0;
	int ans=0;
	lop(i,1,n){
		sum+=a[i];
		while(r<i&&a[i]*(i-r)-sum>m){
			sum-=a[r],r++;
		}
		ans=max(ans,i-r);
	}
	cout<<ans;
	return 0;
}