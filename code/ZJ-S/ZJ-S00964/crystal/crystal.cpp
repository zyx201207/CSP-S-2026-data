#include <bits/stdc++.h>
using namespace std;
long long n,m,i,a[500010],s[500010],sum,ma,j,y;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	for (i=1;i<=n;i++) cin>>a[i];
	if(n<=5000){
		sort(a+1,a+n+1);
		for (i=2;i<=n;i++) s[i]=a[i]-a[i-1];
		for (i=1;i<=n;i++){
			sum=0;
			for (j=i;j<=n;j++){
				sum=sum+(j-i)*s[j];
				if(sum>m) break;
			}
			ma=max(ma,j-i);
		}
		cout<<ma;
		return 0;
	}
	sum=a[2]-a[1];
	for (i=1;i<=n;i++)
		if(1LL*sum*y>m) break;
		else y+=i;
	cout<<i-1;
	return 0;
}
