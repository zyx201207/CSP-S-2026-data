#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,a[N],s[N],m,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=a[i]+s[i-1];
	long long j=1,cnt=0;
	ans=1;
	for(int i=2;i<=n;i++){
		cnt=a[i]*(i-j+1)-s[i]+s[j-1];
		while(cnt>m){
			j++;
			cnt=a[i]*(i-j+1)-s[i]+s[j-1];
		}
	//	cout<<cnt<<"\n";
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	return 0;
}
