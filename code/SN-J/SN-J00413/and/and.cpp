#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
int n,m,a[maxn];
bool check(int x){
	int cnt=0;
	for(int i=1;i<=n;i++)cnt+=((a[i]&x)==x);
	return (cnt>=m);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	int ans=0;
	for(int i=29;i>=0;i--)if(check(ans|(1<<i)))ans|=(1<<i);
	cout<<ans;
	return 0;
}
/*
9:31
Ã»T2ÄÑ£¬µäÌâ 
*/
