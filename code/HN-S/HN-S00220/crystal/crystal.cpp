#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+9;
ll n,m,a[N],s[N],p,k=1;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
		while((i-k+1)*a[i]-s[i]+s[k-1]>m&&k<i)k++;
		p=max(p,i-k+1);
	}
	cout<<p;
	return 0;
}
