#include<bits/stdc++.h>
using namespace std;
long long n,m,a[567891],s[567891],ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	s[0]=0;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	int i=1,j=2;
	while(i<=n){
		while(j<=n&&s[j]-s[i-1]+m>=(a[j]*(j-i+1)))j++;
		if(j-i>ans)ans=j-i;
//		cout<<i<<" "<<j<<endl;
		i++;
	}
	cout<<ans<<endl;
	return 0;
}
