#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],s[N],l,r,mid,maxx;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		l=0,r=i+1;
		while(l+1<r){
			mid=(l+r)/2;
			if(s[i-1]-s[mid-1]-a[i]*(i-mid)>=-m)
				r=mid;
			else
				l=mid;
		}
		maxx=max(maxx,i-r+1);
	}
	cout<<maxx;
	return 0;
}
//我是怎么做到1个小时写完的？？？
//真的能1=吗？后面的题好像骗不到分。
//要AFO了，求求了，1=好不好
//芒果叫万岁
