#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=2e6+10;
int c,t;
int n;
long long d;
long long a[maxn];
long long l[maxn];
long long dp[maxn];
void Test(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		l[i]=lower_bound(a+1,a+i+1,a[i]-d)-a;
	}
		
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
		Test(); 
}
