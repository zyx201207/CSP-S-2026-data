#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
long long a[N+5],s[N+5];
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++)cin>>a[i];
	sort(a+1,a+n+1);
	if(m==1)cout<<a[n]<<endl;
	else if(m==n-1){
		s[1]=a[1];
		long long ans=0;
		for(int i=2;i<=n;i++){
			for(int j=2;j<=n;j++){
				if(j==i)
				s[j]=s[j-1];
				else s[j]=s[j-1]&a[j];
			}
			ans=max(ans,s[n]);
		}
		cout<<ans<<endl;
	}
	else if(m==n){
		s[1]=a[1];
		for(int i=2;i<=n;i++){
			s[i]=s[i-1]&a[i];
		}
		cout<<s[n]<<endl;
	}
	return 0;
}
