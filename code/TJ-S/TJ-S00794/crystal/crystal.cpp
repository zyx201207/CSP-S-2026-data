#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
const int N=5e5+10;
long long a[N],s[N];
int n;long long m;
long long sum;
bool check(int x){
	return m>=(1LL*x*a[x]-s[x]);
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int l=1,r=n;
	int mid;
	while(l<r){
		mid=(l+r+1)/2;
		if(check(mid)){
			l=mid;
		}else{
			r=mid-1;
		}
	}
	cout<<l<<endl;
	return 0;
}

