#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,ans=-0x3f3f3f3f3f3f3f3f;
int a[N],s[N];
bool flag1=true,flag2=true;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i)flag1=0;
		if(i>2){
			if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
				flag2=0;
			}
		}
	}
	if(flag1){
		ans=1;
		int k=0;
		for(int i=1;;i++){
			k+=i;
			if(k>m){
				cout<<ans<<'\n';
				return 0;
			}else ans++;
		}
		return 0;
	}
	if(flag2){
		int m2=0;
		int gc=a[2]-a[1];
		for(int i=1;;i++){
			m2+=pow(gc,i);
			if(m2>m){
				cout<<i<<'\n';
				return 0;
			}
		}
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<i;j++){
			if((s[i]-s[j-1]+m)%a[i]==0){
				ans=max(ans,i-j+1);
			}
		}
	} 
	cout<<ans<<'\n';
	return 0;
} 
