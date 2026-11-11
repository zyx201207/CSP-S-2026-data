#include<bits/stdc++.h>
using namespace std;
#define f(i,a,b)for(long long i = a;i<=b;i++)
#define f_(i,a,b)for(long long i = a;i>=b;i--)
const int N = 5e5+10;
const long long M = 1e12+10;
long long n,m;
long long ar[N],sum[N],br[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	f(i,1,n){
		br[i] = M;
	}
	f(i,1,n){
		cin>>ar[i];
		
	}
	sort(ar+1,ar+1+n);
	f(i,1,n)sum[i] = sum[i-1]+ar[i];
	br[n] = ar[n]*(n-1)-sum[n-1];
	br[1] = 0;
	int ans = 1;
	f(i,2,n-1){
		int bj = 0;
		f_(j,n,i){
			long long t = ar[j]*(i-1)-(sum[j-1]-sum[j-i]);
			//cout<<t<<" "<<j-i<<" ";
			br[i] = min(br[i],t);
			if(br[i]<=m){
				bj = 1;
				break;
			}
		}
		if(bj == 0){
			break;
		}
		ans++;
	}
	cout<<ans;
	return 0;
} 
