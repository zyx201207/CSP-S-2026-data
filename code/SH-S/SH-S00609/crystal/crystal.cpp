#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,ans;
long long a[N],s[N],m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int l=1;ans=1;
	for(int i=2;i<=n;i++){
		while(a[i]*(i-l)-(s[i-1]-s[l-1])>m && l<i) l++;
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
