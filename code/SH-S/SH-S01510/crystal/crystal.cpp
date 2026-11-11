#include<bits/stdc++.h>
using namespace std;
long long a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,cnt=0,x=1,ans=0,h=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		if(cnt+(a[i]-a[i-1])*x>m){
			ans=max(ans,x);
			while(cnt+(a[i]-a[i-1])*x>m){
				x-=1;
				cnt-=a[i-1]-a[h];
				h++;
			}
		}
		cnt+=(a[i]-a[i-1])*x;
		x++;
	}
	ans=max(ans,x);
	cout<<ans;
	return 0;
}
