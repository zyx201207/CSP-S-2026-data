#include<bits/stdc++.h>

using namespace std;

long long n,m,a[500005],ans=1,b[500005],maxx,cnt,s=1,c[500005];


int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(long long i=1;i<n;i++){
		b[i]=a[i+1]-a[i];
	}
	for(long long i=1;i<n;i++){
		c[i]=b[i]+b[i-1];
	} 
	for(long long i=1;i<n;i++){
		if(cnt+(ans*b[i])>m){
			maxx=max(maxx,ans);
			while(cnt+(ans*b[i])>m){
				cnt-=c[i-1]-c[s-1];
				ans--;
				s++;
			}
		}
		cnt+=ans*b[i];
		ans++;
	}
	maxx=max(ans,maxx);
	cout<<maxx;
	return 0;
}
