#include <bits/stdc++.h>
using namespace std;
long long a[500010],n,m;
__int128 qzh[500010];
void write128(__int128 x){
	if(x>9)write128(x/10);
	cerr<<(char)(x%10+48);
}
bool check(int x){
	return qzh[x]-(__int128)1*(a[n]-a[x])*x<=m;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)qzh[i]=qzh[i-1]+a[n]-a[i];
	for(int i=n;i>=1;i--)if(check(i)){
		cout<<i;
		return 0;
	}
	cout<<0;
	return 0;
}
