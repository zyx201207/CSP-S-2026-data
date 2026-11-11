#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll a[N],d[N];
int maxn=-1;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;ll m;
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i)
	d[i]=a[i]-a[i-1];
	for(int i=1;i<=n;++i){
		ll res=0;
		for(int j=i+1;j<=n;++j)
		{
			res+=(j-i)*d[j];
			if(res>m)break;	
			maxn=max(maxn,j-i+1);
		}
	}
	cout<<maxn;
}
