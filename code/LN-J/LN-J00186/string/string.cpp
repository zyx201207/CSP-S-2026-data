#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i]>>c[i];
		a[i]+=a[i-1];
	}
	long long i=1,j=a[n],l=1,r=n,ans=0;
	while(i<=j){
		long long minn=min(a[l]-i+1,j-a[r-1]);
		if(c[l]!=c[r])ans+=minn;
		i+=minn,j-=minn;
		if(i>a[l])++l;
		if(j<=a[r-1])--r;
	}
	cout<<ans;
	return 0;
}
