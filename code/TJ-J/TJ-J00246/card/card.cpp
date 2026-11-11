#include<bits/stdc++.h>
using namespace std;
#define f(i,a,b)for(int i = a;i<=b;i++)
#define f_(i,a,b)for(int i = a;i>=b;i--)
const int N = 2e5+10;
int tong[N],ar[N],n,m,ans[N],br[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	memset(tong,-1,sizeof(tong));
	f(i,1,n){
		cin>>ar[i];
	}
	f_(i,n,1){
		ans[ar[i]] = max(ans[ar[i]],i);
	}
	f(i,1,m){
		cout<<ans[i]<<" ";
	}
}
