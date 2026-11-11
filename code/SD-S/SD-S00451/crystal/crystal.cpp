#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<climits>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<list>
#include<vector>
#include<map>
#include<set>
#include<utility>
using namespace std;
#define ll long long
#define pii pair<int,int>
const int N=5e5+5;
int n,ans=0;
ll m,a[N],sum;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=n,j=n;i>=1;i--){
		while(j>=1&&(i-j)*a[i]-sum<=m) sum=sum+a[--j];
		ans=max(ans,i-j);
		sum-=a[i-1];
	}
	cout<<ans;
	return 0;  
}
