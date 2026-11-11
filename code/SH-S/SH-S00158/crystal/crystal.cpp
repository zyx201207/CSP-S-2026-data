#include<bits/stdc++.h>
using namespace std;
const int N=500010;
long long n,m,a[N],b[N],s[N],l,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)b[i]=a[i]-a[1];
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+b[i];
		while(b[i]*(i-l)-(s[i]-s[l])>m&&l<=i)l++;
		ans=max(ans,i-l);
	}
	cout<<max(1,ans)<<"\n";
	return 0;
}
