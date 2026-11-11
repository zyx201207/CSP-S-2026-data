#include<algorithm>
#include<cmath> 
#include<cstdio> 
#include<iostream> 
#include<deque> 
#include<queue> 
#include<set> 
#include<string> 
#include<stack> 
#include<vector> 
#include<map> 
#include<list> 
using namespace std;
long long a[500005];
int n,ans=0;
long long m,sum=0,summ=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	a[0]=a[1];
	sort(a+1,a+n+1);
	int l=1,r=2;
	while(r<=n){
		sum+=(r-l)*(a[r]-a[r-1]);
		summ+=(a[r]-a[r-1]);
		if(sum<=m){
			ans=max(ans,r-l+1);
		}
		else{
			while(sum>m){
				l++;
				sum-=summ;
				summ-=(a[l]-a[l-1]);
			}
		}
		r++;
	}
	cout<<ans;
	return 0;
}
