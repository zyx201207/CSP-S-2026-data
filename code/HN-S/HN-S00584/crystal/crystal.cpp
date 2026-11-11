#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int a[N],s[N],n,ans=0;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort (a+1,a+n+1);
	int t=a[(n+1)/2];
	for(int i=1;i<=n;i++){
		s[i]=fabs(a[i]-a[t]);
	}
	sort(s+1,s+n+1);
	for(int i=1;i<=n;i++){
		if(s[i]>m) continue;
		else if(m>=0){
			m-=s[i];
			ans++;
		}
		else break;
	}
	cout<<ans;
	return 0;
}
