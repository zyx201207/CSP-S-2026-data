#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500100];
long long sum[500100],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	long long l=1,r=1;
	while(r<=n){
		while((r-l+2)*a[r+1]-(sum[r+1]-sum[l-1])<=m&&r+1<=n){
			r++;
		}
		ans=max(ans,r-l+1);
		l++;
		if(l>r)r=l;
	}
	cout<<ans;
	return 0;
}
/*


5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/



