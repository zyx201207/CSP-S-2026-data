#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+7;
int __=1;
int n,m1,m2,ans=0;
int a[N],l[N];
int c[100];
bool f;
int getlen(int x){
	int cnt=0;
	while(x) x/=2,cnt++;
	return cnt;
}
void solve(){
	cin>>n>>m1;
	m2=m1;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n,greater<int>());
	for(int i=1;i<=n;i++){
		l[i]=getlen(a[i]);
		c[l[i]]++;
	}
	for(int i=1;i<=m1;i++){
		if(c[l[i]]<m2) m1++;
		else{
			if(f==0){
				f=1;
				ans=a[i];
			}else ans&=a[i];
		}
	}
	if(ans==0){
		ans=a[1];
		for(int i=2;i<=m2;i++) ans&=a[i];
	}
	cout<<ans;
	return;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	//cin>>__;
	while(__--) solve();
	return 0;
}

