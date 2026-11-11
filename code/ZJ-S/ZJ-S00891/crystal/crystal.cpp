#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,c,t,a[N],s[N],ans;
bool f=1;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	c=a[2]-a[1];
	t=m;
	for(int i=3;i<=n;i++)
		if(a[i]-a[i-1]!=c){
			f=0;
			break;
		}
	for(int i=1;i<=n&&f;i++){
		t-=(i-1)*c;
		ans++;
		if(t<0){
			ans--;
			break;
		}
	}
	if(f){
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		int t=m,cnt=0;
		for(int j=i;j>=1;j--)
			if(a[i]-a[j]<=t){
				t=t-a[i]+a[j];
				cnt++;
			}else break;
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
