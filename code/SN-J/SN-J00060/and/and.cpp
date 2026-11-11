#include<iostream> 
#include<vector> 
#include<cmath> 
#include<algorithm> 
#include<map> 
#include<set> 
#include<cstdio>
#include<string> 
#include<cstring>
using namespace std;
long long a[200005],ans;
int n,m; 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	ans=a[n-1];
	for(int i=n-2;i>=n-m;i--)
		ans&=a[i]; 
	cout<<ans;
	return 0;
}
