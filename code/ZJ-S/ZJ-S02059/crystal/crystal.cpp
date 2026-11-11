#include<bits/stdc++.h>
#define int long long 
#define For(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define Bor(i,a,b) for(int (i)=(b);(i)>=(a);(i)--)
#define ct continue
#define endl '\n'
using namespace std;
const int N=1e6+5,MOD=1e9,INF=1e18;
int n,m;
int a[N];
int nd[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	For(i,1,n)cin>>a[i];
	sort(a+1,a+1+n);
	int l=1,r=0,sum=0;
	int ans=0;
	while(r<n){
		r++;sum+=a[r];
		int P=a[r],len=r-l+1;
		while((P*(len-1))-(sum-a[r])>m and l<r){
			sum-=a[l];l++;len=r-l+1;
		}
		ans=max(ans,r-l+1);
	}cout<<ans;
	return 0;
}
//i want to play maimaidx
